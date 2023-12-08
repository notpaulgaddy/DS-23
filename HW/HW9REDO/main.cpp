#include <iostream> 
#include <fstream>
#include <vector>
#include <cmath>
#include "Kmer.h"
using namespace std;
unsigned int stringHasher(const string& key) {
	unsigned int hash = 1315423911;//hashnum
	//this implementation is in the readme
	int keySize = key.size();
	for(unsigned int i = 0; i < keySize; i++) {
		hash ^= ((hash << 5) + key[i] + (hash >> 2));
	}
	return hash;
}
void query(const string& fullFileData, vector<Kmer>& givenTable, int kmerInt, int& sizeOfTable)
{
	int highestNum;
	string query;
	cin >> highestNum >> query;
	string key = query.substr(0, kmerInt);
	unsigned int hash = stringHasher(key);
	unsigned int currIndex;
	//loop through finding matching key
	bool match_found = false;
	for (int i = 1; true; i++) {
		//perform hashmap to find key
		int hashedNum = pow(i,i);
		currIndex = (hashedNum+hash) % sizeOfTable;
		//verify if it is a key match
		if (givenTable[currIndex].key == key) {
			break;
		}else{
			cout << "No match" << endl;
		}
	}
	cout << "Query: " << query << endl;
	//loop through given table performing operation
	for(unsigned int i = 0; i < givenTable[currIndex].positions.size(); i++) {
		int newNum = 0;
		//catch query size
		int querSize = query.size();
		//find query in fullFileData
		string found_query = fullFileData.substr(givenTable[currIndex].positions[i], querSize);
		//loop through incrementing  newNum while k of query doesn't equal k of found_query
		for(unsigned int k = kmerInt; k < querSize; k++) {
			if (query[k] != found_query[k]) {
				++newNum;
			}
		}
		//verify that newNum is equal to or less than highestNum and set match to true and output query
		if (newNum < highestNum || newNum==highestNum) {
			match_found = true;
			cout << givenTable[currIndex].positions[i] << " " << newNum << " " << found_query << endl;
		}
	}
	if (!match_found) {
		cout << "No Match" << endl;
	}
}

void tableReHasher(vector<Kmer>& givenTable, int& sizeOfTable) {
	//create new table of new size
	sizeOfTable = 2*sizeOfTable;
	vector<Kmer> new_table(sizeOfTable);
	//cache table size
    int givenTableSize = givenTable.size();
	//loop through given table values
	for (unsigned int i = 0; i < givenTableSize; i++) {
		//verify that the key size for the given key isnt emty
		if (givenTable[i].key.size()>0) {
			unsigned int hash = stringHasher(givenTable[i].key);
			for (int k = 1; true; k++) {
				//perform conversion from hash to hash key
                int hashedNum = pow(k,k);
				unsigned int currIndex = (hashedNum+hash)%sizeOfTable;
				if (new_table[currIndex].key.size() || new_table[currIndex].key == " " || new_table[currIndex].key == "") {
					new_table[currIndex].key = givenTable[i].key;
					//set it to the updated position
					new_table[currIndex].positions = givenTable[i].positions;
					break;
				}
				if (givenTable[i].key == new_table[currIndex].key) {
					break;
				}
			}
		}
	}
	givenTable = new_table;
}

int main() {
	//default table size is 100
	int sizeOfTable = 100;
	ifstream fileFromGenome;//the genome file
	string eachGenomeString;
	//start off with 0 entries of course
	int amtOfEntries = 0; 
	string fullFileData = "";
	int kmerInt = 0;
	float max_occupancy = 0.5;
	vector<Kmer> givenTable(sizeOfTable);
    int ftsSize = fullFileData.size();
	while (cin >> eachGenomeString) {//read the data
        if (eachGenomeString == "TABLE_SIZE" || eachGenomeString == "table_size") {
			cin >> sizeOfTable;
			givenTable.resize(sizeOfTable);
		}
        else if (eachGenomeString == "KMER" || eachGenomeString == "kmer") {
			//IMPLEMENTATION FROM THIS DEV.TO ARTICLE IS IN README
			//get the input stream data
			cin >> kmerInt;
			//continue reading file data
			while (fileFromGenome >> eachGenomeString) {
				fullFileData = fullFileData + eachGenomeString;
			}
            int fdsSize = fullFileData.size();
				for (unsigned int i = 0; i+kmerInt < fdsSize; i++) {
					//get the substring of index i to kmer num for indexing
				string new_key = fullFileData.substr(i, kmerInt);
				//rehash it
				unsigned int hash = stringHasher(new_key);
				for (int k = 1; true; k++) {
					unsigned int currIndex = (hash+k*k)%sizeOfTable;
					//if its empty
					if (givenTable[currIndex].key == " " || givenTable[currIndex].key == "") {
						givenTable[currIndex].key = new_key;//swap keys
						givenTable[currIndex].positions.push_back(i);//append it
						//iterate thru the amt of entries
						amtOfEntries++;
						if (max_occupancy<(float)amtOfEntries/sizeOfTable) {//if the avg is greater than the max occup number 
							tableReHasher(givenTable, sizeOfTable);//we rehash
						}
						break;
					}
					if (givenTable[currIndex].key == new_key) {//if its a match
            //then we append the item to the current table
						givenTable[currIndex].positions.push_back(i);
					}
				}
			}

		}
		else if (eachGenomeString == "GENOME" || eachGenomeString == "genome") {
			cin >> eachGenomeString;
			fileFromGenome.open(eachGenomeString.c_str());
		}
		else if (eachGenomeString == "OCCUPANCY" ||  eachGenomeString == "occupancy") {
			cin >> max_occupancy;
		}
		
		else if (eachGenomeString == "QUERY" || eachGenomeString == "query") {
			query(fullFileData, givenTable, kmerInt, sizeOfTable);
		}
		else if (eachGenomeString == "QUIT" || eachGenomeString == "quit") {
			break;
		}
		else {
			//wrong command, error checking
            cout << "Unrecognized command." << endl;
		}
	}

	return 0;
}