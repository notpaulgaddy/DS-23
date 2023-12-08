#include <iostream>
#include <string>
#include <fstream>
#include "hash_linear_probe.h"
#include "hash_double_hashing.h"

int main() {
    std::string command, filename;
    int table_size = 100, k = 10;
    float occupancy = 0.5;
    HashLinearProbe hash_lp(table_size, occupancy);
    HashTableDoubleHashing<int, int> hash_dh(table_size, occupancy);
    
    while (std::cin >> command) {
        if (command == "genome") {
            std::cin >> filename;
            std::ifstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error opening file " << filename << std::endl;
                continue;
            }

            // read genome file and build hash tables
            std::string line, genome;
            while (std::getline(file, line)) {
                if (!line.empty()) {
                    genome += line;
                }
            }

            for (int i = 0; i <= genome.size() - k; i++) {
                std::string kmer = genome.substr(i, k);
                hash_lp.insert(kmer, i);
                hash_dh.insert(kmer, i);
            }
        }
        else if (command == "table_size") {
            std::cin >> table_size;
            hash_lp.setTableSize(table_size);
            hash_dh.setTableSize(table_size);
        }
        else if (command == "occupancy") {
            std::cin >> occupancy;
            hash_lp.setOccupancy(occupancy);
            hash_dh.setOccupancy(occupancy);
        }
        else if (command == "kmer") {
            std::cin >> k;
        }
        else if (command == "query") {
            int m;
            std::string query;
            std::cin >> m >> query;

            std::string seed = query.substr(0, k);
            int seed_index_lp = hash_lp.search(seed);
            int seed_index_dh = hash_dh.search(seed);

            if (seed_index_lp == -1 || seed_index_dh == -1) {
                std::cout << "Seed not found: " << seed << std::endl;
                continue;
            }

            std::cout << "Seed found at index " << seed_index_lp << std::endl;

            // check for mismatches
            int mismatches = 0;
            for (int i = k; i < query.size(); i++) {
                if (query[i] != hash_lp.getGenome()[seed_index_lp + i - k]) {
                    mismatches++;
                }
                if (mismatches > m) {
                    break;
                }
            }

            if (mismatches <= m) {
                std::cout << "Query found at position " << seed_index_lp << std::endl;
            } else {
                std::cout << "Query not found" << std::endl;
            }
        }
        else if (command == "quit") {
            break;
        }
    }

    return 0;
}
