#include <string>

template <typename V>
class MapNode {
    public:
    std::string key;
    V value;
    MapNode<V> *next;

    MapNode(std::string key, V value) {
        this -> key = key;
        this -> value = value;
        next = nullptr;
    }

    ~MapNode() {
        delete next;
    }
};

template <typename V>
class Hashmap {
    MapNode<V> **buckets;
    int numBuckets;
    int _size;

    static constexpr double LOAD_FACTOR_THRESHOLD = 0.7;

public:
    Hashmap() {
        initialize(5);
    }
    
private:
    void initialize(int numBuckets) {
        this -> numBuckets = numBuckets;
        _size = 0;

        buckets = new MapNode<V>*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = nullptr;
        }
    }

    int getBucketIndex(std::string key) {
        int hashCode = 0;
        int coeff = 1;

        for (int i = key.length() - 1; i >= 0; i--) {
            hashCode = (hashCode + key[i] * coeff) % numBuckets;
            coeff = (coeff * 37) % numBuckets;
        }
        return hashCode % numBuckets;
    }

    MapNode<V>* findKey(std::string key) {
        int bucketIndex = getBucketIndex(key);
        return findKey(key, bucketIndex);
    }

    MapNode<V>* findKey(std::string key, int bucketIndex) {
        MapNode<V> *head = buckets[bucketIndex];

        while (head != nullptr) {
            if (head -> key == key) {
                return head;
            }
            head = head -> next;
        }
        return nullptr;
    }

    double loadFactor() {
        return (double) _size / numBuckets;
    }

    void rehash() {
        MapNode<V> **temp = buckets;
        int oldNumBuckets = numBuckets;
        
        initialize(2 * numBuckets);

        for (int i = 0; i < oldNumBuckets; i++) {
            MapNode<V> *head = temp[i];

            while (head != nullptr) {
                std::string key = head -> key;
                V value = head -> value;

                insert(key, value);

                head = head -> next;
            }
        }

        freeMem(temp, oldNumBuckets);
    }

    void freeMem(Hashmap<V> **arr, int n) {
        for (int i = 0; i < n; i++) {
            delete arr[i];
        }
        delete [] arr;
    }

public:
    void insert(std::string key, V value) {
        int bucketIndex = getBucketIndex(key);

        MapNode<V> *head = findKey(key, bucketIndex);

        if (head) {
            head -> value = value;
            return ;
        }

        MapNode<V> *node = new MapNode<V>(key, value);

        node -> next = buckets[bucketIndex];
        buckets[bucketIndex] = node;

        _size++;

        double lf = loadFactor();

        if (lf > LOAD_FACTOR_THRESHOLD) {
            rehash();
        }
    }

    V get(std::string key) {
        MapNode<V> *head = findKey(key);
        return (head) ? head -> value : 0;
    }

    V remove(std::string key) {
        int bucketIndex = getBucketIndex(key);

        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = nullptr;

        while (head != nullptr) {
            if (head -> key == key) {
                break;
            }
            prev = head;
            head = head -> next;
        }
        if (!head) {
            return 0;
        }

        V value = head -> value;

        if (prev) {
            prev -> next = head -> next;
        }
        else {
            buckets[bucketIndex] = head -> next;
        }

        head -> next = nullptr;
        delete head;

        _size--;

        return value;
    }

    int size() {
        return _size;
    }

    ~Hashmap() {
        freeMem(buckets, numBuckets);
    }
};
