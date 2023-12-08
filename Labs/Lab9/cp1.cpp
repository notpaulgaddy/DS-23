// #include <iostream>
// #include <fstream>
// #include <map>
// #include <vector>

// using namespace std;

// int main(int argc, char* argv[])
// {
//     // check for input file argument
//     if (argc != 2) {
//         cerr << "Usage: " << argv[0] << " input_file" << endl;
//         return 1;
//     }

//     // open input file
//     ifstream input_file(argv[1]);
//     if (!input_file) {
//         cerr << "Error: could not open input file " << argv[1] << endl;
//         return 1;
//     }

//     // read integers from input file into vector
//     vector<int> nums;
//     int num;
//     while (input_file >> num) {
//         nums.push_back(num);
//     }

//     // find frequencies of integers using map
//     map<int, int> freqs;
//     for (int i = 0; i < nums.size(); i++) {
//         freqs[nums[i]]++;
//     }

//     // find modes
//     vector<int> modes;
//     int max_freq = 0;
//     for (map<int, int>::iterator it = freqs.begin(); it != freqs.end(); it++) {
//         if (it->second > max_freq) {
//             modes.clear();
//             modes.push_back(it->first);
//             max_freq = it->second;
//         } else if (it->second == max_freq) {
//             modes.push_back(it->first);
//         }
//     }

//     // print modes
//     if (modes.size() == 0) {
//         cout << "There are no modes in the input sequence." << endl;
//     } else if (modes.size() == 1) {
//         cout << "The mode is " << modes[0] << "." << endl;
//     } else {
//         cout << "The modes are ";
//         for (int i = 0; i < modes.size(); i++) {
//             cout << modes[i];
//             if (i < modes.size() - 1) {
//                 cout << ", ";
//             }
//         }
//         cout << "." << endl;
//     }

//     return 0;
// }
