// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <cstdlib>
// #include <ctime>
// #include <unordered_set>
// using namespace std;

// // void moveAroundGrid(int height, int width, vector<string> posWords, vector<string> negWords, vector<vector<char> > matrix){
// //     //recursive, look around grid
// //     //go diagonal and horizontal
// //     int goodCount = 0;
// //     bool foundMinusWord = false;
// //     bool foundPlusWord = false;
    
// // }

// // vector<vector<char> > gridMake(int height, int width, vector<string> posWords, vector<string> negWords){
// //     // Create 2D matrix with random letters
// //     vector<vector<char> > matrix(height, vector<char>(width));
// //     srand(time(NULL));  // Seed random number generator
// //     for (int i = 0; i < height; i++) {
// //         for (int j = 0; j < width; j++) {
// //             matrix[i][j] = 'A' + rand() % 26;  // Assign random letter between A and Z
// //             //cout << matrix[i][j] << " ";  // Print matrix element
// //         }
// //         //cout << endl;
// //     }
// //     //return matrix;
// //     moveAroundGrid(height, width, posWords, negWords, matrix);
// // }


// vector<char> uniqueLetters(vector<string>& words) {
//     unordered_set<char> letters;
//     for (string word : words) {
//         for (char c : word) {
//             letters.insert(c);
//         }
//     }
//     vector<char> result(letters.begin(), letters.end());
//     return result;
// }

// int main(int argc, char* argv[]) {
//     ifstream infile(argv[1]);   // Open input file
//     int width, height;
//     infile >> width >> height;  // Read width and height from file
//     vector<string> posWords;   // Vector to store positive words
//     vector<string> negWords;   // Vector to store negative words
    
//     // Read words from file and store them in respective vectors
//     char sign;
//     string word;
//     while (infile >> sign >> word) {
//         if (sign == '+') {
//             posWords.push_back(word);
//         } else if (sign == '-') {
//             negWords.push_back(word);
//         }
//     }
    
//     // Print the positive and negative words
//     std::cout << "Positive words: ";
//     for (int i = 0; i < posWords.size(); i++) {
//         std::cout << posWords[i] << " ";
//     }
//     std::cout << endl;
//     //make a new vector of words that should appear 
//     std::cout << "Negative words: ";
//     for (int i = 0; i < negWords.size(); i++) {
//         std::cout << negWords[i] << " ";
//     }
//     std::cout << endl;
//     //gridMake(height, width, posWords, negWords);
//     vector<char> letters = uniqueLetters(posWords);
//     for (char c : letters) {
//         cout << c << " ";
//     }
//     return 0;
// }
