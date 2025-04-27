#include <vector>
#include <cmath>
#include <functional>
#include <cstdint>

namespace Filter {
    template <typename K>
    class BloomFilter {
        std::vector<bool> set;
        uint32_t k;

    public:
        BloomFilter(size_t n, float p) {
            size_t capacity = -(n * log(p)) / (log(2) * log(2));
            set.resize(capacity, false);

            k = (capacity / n) * log(2);
        }

    private:
        int hash(K key, unsigned int index) const {
            size_t h = std::hash<K>{}(key) ^ (index * 0x9e3779b9 + (index << 6) + (index >> 2));
            return static_cast<int>(h % set.size());
        }

    public:
        void insert(K key) {
            for (uint32_t i = 0; i < k; i++) {
                int h = hash(key, i);
                set[h] = true;
            }
        }

        bool mayContain(K key) const {
            for (uint32_t i = 0; i < k; i++) {
                int h = hash(key, i);

                if (!set[h]) {
                    return false;
                }
            }
            return true;
        }
    };
}
