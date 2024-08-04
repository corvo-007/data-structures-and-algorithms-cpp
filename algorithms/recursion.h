#include <iostream>

namespace Recursion {

	unsigned int factorial(unsigned int n) {
		if (n <= 1) {
			return 1;
		}
		return n * factorial(n - 1);
	}

	unsigned int factorial_tail_recursion(unsigned int n, unsigned int acc) {
		if (n <= 1) {
			return acc;
		}
		return factorial_tail_recursion(n - 1, n * acc);
	}

	unsigned int factorial_tail_recursion(unsigned int n) {
		return factorial_tail_recursion(n, 1);
	}

	double exponentiate(int x, int n) {
		if (n < 0) {
			return 1 / exponentiate(x, -n);
		}
		if (n == 0) {
			return 1;
		}
		return x * exponentiate(x, n - 1);
	}

	double exponentiate_tail_recursion(int x, int n, int acc) {
		if (n < 0) {
			return 1 / exponentiate_tail_recursion(x, -n, acc);
		}
		if (n == 0) {
			return acc;
		}
		return exponentiate_tail_recursion(x, n - 1, x * acc);
	}

	double exponentiate_tail_recursion(int x, int n) {
		return exponentiate_tail_recursion(x, n, 1);
	}

	double exponentiate_optimised(int x, int n) {
		if (n < 0) {
			return 1 / exponentiate_optimised(x, -n);
		}
		if (n == 0) {
			return 1;
		}
		if (n & 1) {
			return x * exponentiate_optimised(x * x, (n - 1) >> 1);
		}
		return exponentiate_optimised(x * x, n >> 1);
	}

	double exponentiate_optimised_tail_recursive(int x, int n, int acc) {
		if (n < 0) {
			return 1 / exponentiate_optimised_tail_recursive(x, -n, acc);
		}
		if (n == 0) {
			return acc;
		}
		if (n & 1) {
			return exponentiate_optimised_tail_recursive(x * x, (n - 1) >> 1, x * acc);
		}
		return exponentiate_optimised_tail_recursive(x * x, n >> 1, acc);
	}

	double exponentiate_optimised_tail_recursive(int x, int n) {
		return exponentiate_optimised_tail_recursive(x, n, 1);
	}

	void towerOfHanoi(int n, char s = 'a', char a = 'b', char d = 'c') {
		if (n <= 0) {
			return ;
		}
		towerOfHanoi(n - 1, s, d, a);
		std::cout << s << " -> " << d << '\n';
		towerOfHanoi(n - 1, a, s, d);
	}
}
