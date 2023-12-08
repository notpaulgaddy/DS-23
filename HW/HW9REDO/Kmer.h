#include <string>
#include <vector>

using namespace std;

class Kmer {
public:
	Kmer() : key("") {}//takes in string
	string key;//the key we take in
	vector<int> positions;//the position of each item in the hashmap

	// Kmer& operator=(const Kmer& other) {
	// 	if (this == &other) {
	// 		return *this;
	// 	}
	// 	key = other.key;
	// 	positions = other.positions;
	// 	return *this;
	// }
};
