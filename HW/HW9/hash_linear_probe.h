#ifndef HASH_LINEAR_PROBE_H
#define HASH_LINEAR_PROBE_H

#include <iostream>
#include <vector>

template <typename Key, typename Value>
class HashLinearProbe {
public:
     //HashLinearProbe(size_t size) : table(size), occupancy(0.0) {}
    HashLinearProbe(int size = 100, float occ = 0.5) : table_size(size), occupancy(occ), size(0) {
        table.resize(table_size);
    }


    void insert(Key key, Value value) {
        int index = hash(key);
        int originalIndex = index;

        while (!table[index].empty() && table[index].front().first != key) {
            index = (index + 1) % maxSize;
            if (index == originalIndex) {
                throw std::runtime_error("Table is full");
            }
        }

        if (table[index].empty()) {
            occupancy += 1.0 / maxSize;
        }

        table[index].emplace_back(key, value);

        if (occupancy > maxOccupancy) {
            resize(maxSize * 2);
        }
    }

    std::vector<Value> get(Key key) const {
        int index = findIndex(key);
        if (index == -1) {
            return {};
        }
        std::vector<Value> values;
        for (const auto& item : table[index]) {
            values.push_back(item.second);
        }
        return values;
    }

    void clear() {
        table.clear();
        occupancy = 0;
        maxSize = 100;
        table.resize(maxSize);
    }

private:
    std::vector<std::vector<std::pair<Key, Value>>> table;
    double occupancy;
    int maxSize;
    double maxOccupancy = 0.5;

    int hash(Key key) const {
        std::hash<Key> hash_fn;
        return hash_fn(key) % maxSize;
    }

    int findIndex(Key key) const {
        int index = hash(key);
        int originalIndex = index;

        while (!table[index].empty() && table[index].front().first != key) {
            index = (index + 1) % maxSize;
            if (index == originalIndex) {
                return -1;
            }
        }

        if (table[index].empty()) {
            return -1;
        }

        return index;
    }

    void resize(int newMaxSize) {
        std::vector<std::vector<std::pair<Key, Value>>> newTable(newMaxSize);
        for (const auto& bucket : table) {
            for (const auto& item : bucket) {
                int newIndex = hash(item.first);
                while (!newTable[newIndex].empty()) {
                    newIndex = (newIndex + 1) % newMaxSize;
                }
                newTable[newIndex].push_back(item);
            }
        }
        table = newTable;
        maxSize = newMaxSize;
    }
};

#endif  // HASH_LINEAR_PROBE_H
