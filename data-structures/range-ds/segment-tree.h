#include <vector>
#include <climits>
#include <cstdint>

namespace RangeDS {

	class SegmentTree {
		struct S_Node {
			int min;
			int max;
			int sum;
			int left;
			int right;

			S_Node(int min, int max, int sum, int left, int right): min(min), max(max), sum(sum), left(left), right(right) {

			}
		};

		std::vector<S_Node*> tree;

	public:
		SegmentTree(const std::vector<int> &vec) {
			build(vec);
		}

		SegmentTree(int *arr, int n) {
			std::vector<int> temp(arr, arr + n);
			build(temp);
		}

	private:
		void build(const std::vector<int> &vec) {
			tree.resize(4 * vec.size());
			build(0, 0, vec.size() - 1, vec);
		}

		void build(int index, int l, int r, const std::vector<int> &vec) {
			if (l == r) {
				tree[index] = new S_Node(vec[l], vec[l], vec[l], l, r);
				return ;
			}

			int mid = l + (r - l) / 2;
			int child1 = 2 * index + 1;
			int child2 = child1 + 1;
			build(child1, l, mid, vec);
			build(child2, mid + 1, r, vec);

			S_Node *child1_ptr = tree[child1];
			S_Node *child2_ptr = tree[child2];

			tree[index] = new S_Node(std::min(child1_ptr -> min, child2_ptr -> min), std::max(child1_ptr -> max, child2_ptr -> max), child1_ptr -> sum + child2_ptr -> sum, l, r);
		}

		void update(int i, int index, int value) {
			if (tree[i] -> left == tree[i] -> right) {
				if (tree[i] -> left == index) {
					tree[i] -> min = value;
					tree[i] -> max = value;
					tree[i] -> sum = value;
				}
				return ;
			}

			int mid = tree[i] -> left + (tree[i] -> right - tree[i] -> left) / 2;
			int child1 = 2 * i + 1;
			int child2 = child1 + 1;
			if (index <= mid) {
				update(child1, index, value);
			}
			else {
				update(child2, index, value);
			}

			tree[i] -> min = std::min(tree[child1] -> min, tree[child2] -> min);
			tree[i] -> max = std::max(tree[child1] -> max, tree[child2] -> max);
			tree[i] -> sum = tree[child1] -> sum + tree[child2] -> sum;
		}

		int process(int index, int l, int r, uint8_t &op) const {
			if (tree[index] -> right < l || r < tree[index] -> left) {
				return (op == 0) ? INT_MAX : (op == 1) ? INT_MIN : 0;
			}
			if (tree[index] -> left >= l && tree[index] -> right <= r) {
				return (op == 0) ? tree[index] -> min : (op == 1) ? tree[index] -> max : tree[index] -> sum;
			}


			int left_data = process(2 * index + 1, l, r, op);
			int right_data = process(2 * index + 2, l, r, op);

			return (op == 0) ? std::min(left_data, right_data) : (op == 1) ? std::max(left_data, right_data) : left_data + right_data;
		}

	public:
		void update(int index, int value) {
			update(0, index, value);
		}

		int min(int l, int r) const {
			uint8_t op = 0;
			return process(0, l, r, op);
		}

		int max(int l, int r) const {
			uint8_t op = 1;
			return process(0, l, r, op);
		}

		int sum(int l, int r) const {
			uint8_t op = 2;
			return process(0, l, r, op);
		}

		~SegmentTree() {
			for (auto i: tree) {
				delete i;
			}
		}
	};

}
