#include "../../common/D_Node.h"

template <typename T>
class DoublyLinkedList {
	D_Node<T> *head;
	D_Node<T> *tail;
	int _size;

public:
	DoublyLinkedList<T>(): head(nullptr), tail(nullptr), _size(0) {

	}

	void push_front(T data) {
		D_Node<T> *newNode = new D_Node<T>(data);

		if (head) {
			head -> prev = newNode;
			newNode -> next = head;
		}
		else {
			tail = newNode;
		}

		head = newNode;
		_size++;
	}

	void push_back(T data) {
		D_Node<T> *newNode = new D_Node<T>(data);

		if (head) {
			tail -> next = newNode;
			newNode -> prev = tail;
		}
		else {
			head = newNode;
		}

		tail = newNode;
		_size++;
	}

	void pop_front() {
		if (_size == 0) {
			return ;
		}

		if (_size == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			_size = 0;
			return ;
		}

		D_Node<T> *temp = head;
		head = head -> next;
		delete temp;
		head -> prev = nullptr;
		_size--;
	}

	void pop_back() {
		if (_size == 0) {
			return ;
		}

		if (_size == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			_size = 0;
			return ;
		}

		D_Node<T> *temp = tail;
		tail = tail -> prev;
		delete temp;
		tail -> next = nullptr;
		_size--;
	}

	T front() {
		return (_size != 0) ? head -> data : 0;
	}

	T back() {
		return (_size != 0) ? tail -> data : 0;
	}

	int size() {
		return _size;
	}

	bool empty() {
		return _size == 0;
	}

	~DoublyLinkedList() {
		while (head) {
			D_Node<T> *temp = head;
			head = head -> next;
			delete temp;
		}
	}
};
