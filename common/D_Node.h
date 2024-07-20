template <typename T>
class D_Node {
public:
	T data;
	D_Node<T> *prev;
	D_Node<T> *next;

	D_Node<T>(T data): data(data), prev(nullptr), next(nullptr) {

	}
};