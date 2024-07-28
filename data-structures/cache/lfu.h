#include <unordered_map>
#include "../../common/D_Node.h"

namespace Cache {
	template <typename K, typename V> using CacheNode = D_Node<std::pair<K, V>>;

	template <typename K, typename V>
	class LFUCache {
		std::unordered_map<int, std::pair<CacheNode<K, V>*, CacheNode<K, V>*>> freq_map;
		std::unordered_map<K, std::pair<CacheNode<K, V>*, int>> node_map;
		int minFreq;
		int _capacity;

	public:
		LFUCache<K, V>(int _capacity): minFreq(0), _capacity(_capacity) {

		}

	private:
		void push(int freq, CacheNode<K, V> *node) {
			if (!freq_map.count(freq)) {
				freq_map[freq] = { node, node };
				return ;
			}

			std::pair<CacheNode<K, V>*, CacheNode<K, V>*> &p = freq_map[freq];

			p.first -> prev = node;
			node -> next = p.first;
			p.first = node;
		}

		void increaseFrequency(std::pair<CacheNode<K, V>*, int> &p_node) {
			CacheNode<K, V> *node = p_node.first;
			int freq = p_node.second;
			std::pair<CacheNode<K, V>*, CacheNode<K, V>*> &p = freq_map[freq];

			if (p.first == node && p.second == node) {
				freq_map.erase(freq);
				if (minFreq == freq) {
					minFreq = freq + 1;
				}
			}
			else {
				CacheNode<K, V> *prev = node -> prev;
				CacheNode<K, V> *next = node -> next;
				node -> prev = nullptr;
				node -> next = nullptr;

				if (prev) {
					prev -> next = next;
				}
				else {
					p.first = next;
				}
				
				if (next) {
					next -> prev = prev;
				}
				else {
					p.second = prev;
				}
			}
			push(freq + 1, node);
			p_node.second++;
		}

		void pop() {
			std::pair<CacheNode<K, V>*, CacheNode<K, V>*> &p = freq_map[minFreq];
			if (p.first == p.second) {
				delete p.first;
				freq_map.erase(minFreq);
				return ;
			}

			CacheNode<K, V> *temp = p.second;
			p.second = temp -> prev;
			p.second -> next = nullptr;
			delete temp;
		}

	public:
		void put(K key, V value) {
			if (node_map.count(key)) {
				node_map[key].first -> data.second = value;
				increaseFrequency(node_map[key]);
				return ;
			}

			if (node_map.size() == _capacity) {
				node_map.erase(freq_map[minFreq].second -> data.first);
				pop();
			}

			CacheNode<K, V> *node = new CacheNode<K, V>({ key, value });
			node_map[key] = { node, 1 };
			minFreq = 1;
			push(1, node);
		}

		V get(K key) {
			if (!node_map.count(key)) {
				return 0;
			}

			V value = node_map[key].first -> data.second;
			increaseFrequency(node_map[key]);
			return value;
		}

		int size() {
			return node_map.size();
		}

		int capacity() {
			return _capacity;
		}

		bool empty() {
			return node_map.size() == 0;
		}

		~LFUCache() {
			typename std::unordered_map<K, std::pair<CacheNode<K, V>*, int>>::iterator it = node_map.begin();

			while (it != node_map.end()) {
				delete it -> second.first;
				it++;
			}
		}
	};
}
