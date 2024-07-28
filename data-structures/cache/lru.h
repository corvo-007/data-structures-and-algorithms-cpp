#include <unordered_map>
#include "../../common/D_Node.h"

namespace Cache {
	template <typename K, typename V> using CacheNode = D_Node<std::pair<K, V>>;

	template <typename K, typename V>
	class LRUCache {
		CacheNode<K, V> *head;
		CacheNode<K, V> *tail;
		int _capacity;

		std::unordered_map<K, CacheNode<K, V>*> node_map;

	public:
		LRUCache(int _capacity): head(nullptr), tail(nullptr), _capacity(_capacity) {

		}

	private:
		void push_front(CacheNode<K, V> *node_ptr) {
			if (!head) {
				head = node_ptr;
				tail = node_ptr;
				return ;
			}

			node_ptr -> next = head;
			head -> prev = node_ptr;
			head = node_ptr;
		}

		void makeRecent(CacheNode<K, V> *node_ptr) {
			if (head == node_ptr) {
				return ;
			}

			CacheNode<K, V> *prev = node_ptr -> prev;
			CacheNode<K, V> *next = node_ptr -> next;

			prev -> next = next;
			if (next) {
				next -> prev = prev;
			}
			else {
				tail = prev;
			}

			node_ptr -> prev = nullptr;
			node_ptr -> next = head;
			head -> prev = node_ptr;
			head = node_ptr;
		}

		void pop_back() {
			if (!head) {
				return ;
			}
			if (head == tail) {
				delete head;
				head = nullptr;
				tail = nullptr;
				return ;
			}

			CacheNode<K, V> *temp = tail;
			tail = tail -> prev;
			tail -> next = nullptr;
			delete temp;
		}

	public:
		void put(K key, V value) {
			if (node_map.count(key)) {
				node_map[key] -> data.second = value;
				makeRecent(node_map[key]);
				return ;
			}

			if (node_map.size() == _capacity) {
				node_map.erase(tail -> data.first);
				pop_back();
			}

			CacheNode<K, V> *newNode = new CacheNode<K, V>({ key, value });

			node_map[key] = newNode;
			push_front(newNode);
		}

		V get(K key) {
			if (!node_map.count(key)) {
				return 0;
			}
			V value = node_map[key] -> data.second;
			makeRecent(node_map[key]);
			return value;
		}

		int size() {
			return node_map.size();
		}

		int capacity() {
			return _capacity;
		}

		bool empty() {
			return node_map.empty();
		}
	};
}
