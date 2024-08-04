#include <vector>

namespace RangeDS {

	class FenwickTree {
		int *tree;
		int size;

	public:
		FenwickTree(int size) {
			this -> size = size + 1;
			tree = new int[this -> size];
			std::fill(tree, tree + this -> size, 0);
		}

		FenwickTree(const std::vector<int> &vec): FenwickTree(vec.size()) {
			build(vec);
		}

		FenwickTree(const int *arr, int n): FenwickTree(n) {
			const std::vector<int> vec(arr, arr + n);
			build(vec);
		}

	private:
		void build(const std::vector<int> &vec) {
			for (int i = 1; i < size; i++) {
				tree[i] += vec[i - 1];
				int j = i + (i & -i);
				if (j < size) {
					tree[j] += tree[i];
				}
			}
		}

	public:
		void update(int i, int value) {
			i++;

			while (i < size) {
				tree[i] += value;
				i += (i & -i);
			}
		}

		int sum(int i) const {
			i++;
			int s = 0;

			while (i > 0) {
				s += tree[i];
				i -= (i & -i);
			}
			return s;
		}

		int sum(int l, int r) const {
			return sum(r) - sum(l - 1);
		}

		~FenwickTree() {
			delete [] tree;
		}
	};
}
