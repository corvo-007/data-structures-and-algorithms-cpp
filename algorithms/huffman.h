#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include "../common/functions.h"
#include "../common/binaryTreeNode.h"

namespace Compression {

	using p_queue = std::priority_queue<std::pair<int, BinaryTreeNode<char>*>, std::vector<std::pair<int, BinaryTreeNode<char>*>>, std::greater<std::pair<int, BinaryTreeNode<char>*>>>;

	class HuffmanCompressor {
	public:
		HuffmanCompressor() {

		}

	private:
		BinaryTreeNode<char>* constructTree(p_queue &pq) {

			while (pq.size() != 1) {
				auto left = pq.top();
				pq.pop();
				auto right = pq.top();
				pq.pop();

				BinaryTreeNode<char> *node = new BinaryTreeNode<char>('\0');
				node -> left = left.second;
				node -> right = right.second;

				pq.push({ left.first + right.first, node });
			}
			return pq.top().second;
		}

		void generateCode(BinaryTreeNode<char> *root, std::string &code, std::unordered_map<char, std::string> &map) {
			if (!root) {
				return ;
			}
			if (root -> data != '\0') {
				map[root -> data] = code;
				return ;
			}

			code += '0';
			generateCode(root -> left, code, map);
			code.pop_back();

			code += '1';
			generateCode(root -> right, code, map);
			code.pop_back();
		}

		std::unordered_map<char, std::string> generateCodes(BinaryTreeNode<char> *root) {
			std::unordered_map<char, std::string> map;

			std::string code = "";
			generateCode(root, code, map);

			return map;
		}

		std::string _compress(const std::string &input) {
			if (input.length() == 0) {
				return "";
			}

			std::unordered_map<char, int> freq_map = frequencyCount(input);

			p_queue pq;

			auto it = freq_map.begin();
			while (it != freq_map.end()) {
				pq.push({ it -> second, new BinaryTreeNode<char>(it -> first) });
				it++;
			}

			BinaryTreeNode<char> *root = constructTree(pq);

			std::unordered_map<char, std::string> code_map = generateCodes(root);

			delete root;

			std::string output = "";

			for (char c: input) {
				output += code_map[c];
			}

			return output;
		}

	public:
		std::string compress(const std::string &input) {
			return _compress(input);
		}
	};
}
