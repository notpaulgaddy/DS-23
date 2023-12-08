#ifndef HASH_DOUBLE_HASHING_H
#define HASH_DOUBLE_HASHING_H

#include <vector>
#include <stdexcept>

template<typename KeyType, typename ValueType>
class HashTableDoubleHashing {
public:
    HashTableDoubleHashing(int table_size, double max_load_factor)
            : table_size_(table_size), max_load_factor_(max_load_factor),
              size_(0), table_(table_size_) {}

    void Insert(const KeyType &key, const ValueType &value) {
        if (LoadFactor() > max_load_factor_) {
            Rehash(table_size_ * 2);
        }
        int index = FindIndex(key);
        if (table_[index].first == key) {
            throw std::invalid_argument("Key already exists.");
        }
        table_[index] = {key, value};
        size_++;
    }

    void Remove(const KeyType &key) {
        int index = FindIndex(key);
        if (table_[index].first != key) {
            throw std::invalid_argument("Key does not exist.");
        }
        table_[index].first = KeyType();
        table_[index].second = ValueType();
        size_--;
    }

    bool Contains(const KeyType &key) const {
        return table_[FindIndex(key)].first == key;
    }

    const ValueType &Get(const KeyType &key) const {
        int index = FindIndex(key);
        if (table_[index].first != key) {
            throw std::invalid_argument("Key does not exist.");
        }
        return table_[index].second;
    }

    ValueType &GetMutable(const KeyType &key) {
        int index = FindIndex(key);
        if (table_[index].first != key) {
            throw std::invalid_argument("Key does not exist.");
        }
        return table_[index].second;
    }

    void Clear() {
        table_.clear();
        table_.resize(table_size_);
        size_ = 0;
    }

    double LoadFactor() const {
        return static_cast<double>(size_) / table_size_;
    }

    int Size() const {
        return size_;
    }

private:
    int table_size_;
    double max_load_factor_;
    int size_;
    std::vector<std::pair<KeyType, ValueType>> table_;

    int HashFunction(const KeyType &key) const {
        return std::hash<KeyType>()(key) % table_size_;
    }

    int HashFunction2(const KeyType &key) const {
        return 1 + (std::hash<KeyType>()(key) % (table_size_ - 1));
    }

    int FindIndex(const KeyType &key) const {
        int index = HashFunction(key);
        int i = 1;
        while (table_[index].first != KeyType() && table_[index].first != key) {
            index = (index + i * HashFunction2(key)) % table_size_;
            i++;
        }
        return index;
    }

    void Rehash(int new_size) {
        std::vector<std::pair<KeyType, ValueType>> old_table = table_;
        table_.clear();
        table_.resize(new_size);
        table_size_ = new_size;
        size_ = 0;
        for (auto &entry : old_table) {
            if (entry.first != KeyType()) {
                Insert(entry.first, entry.second);
            }
        }
    }
};

#endif // HASH_DOUBLE_HASHING_H
