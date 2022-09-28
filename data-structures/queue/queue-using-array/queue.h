template <typename T>
class Queue {
    T *data;
    int frontIndex;
    int nextIndex;
    int _size;
    int capacity;

    public:
    
    Queue(int capacity) {
        data = new T[capacity];
        frontIndex = -1;
        nextIndex = 0;
        _size = 0;
        this -> capacity = capacity;
    }

    void push(T element) {
        if (_size == capacity) {
            T *temp = data;
            data = new T[2 * capacity];
            int k = 0;
            for (int i = frontIndex; i < capacity; i++, k++) {
                data[k] = temp[i];
            }
            for (int i = 0; i < frontIndex; i++, k++) {
                data[k] = temp[i];
            }
            delete [] temp;
            frontIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (frontIndex == -1) {
            frontIndex = 0;
        }
        _size++;
    }

    T pop() {
        if (_size == 0) {
            return 0;
        }
        T element = data[frontIndex];
        _size--;
        if (_size == 0) {
            frontIndex = -1;
            nextIndex = 0;
        }
        else {
            frontIndex = (frontIndex + 1) % capacity;
        }
        return element;
    }

    T front() const {
        if (_size == 0) {
            return 0;
        }
        return data[frontIndex];
    }

    int size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }
};