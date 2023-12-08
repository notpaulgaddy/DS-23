#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    char str[100]; // declare the size of string
    cout << " Enter a string: " << endl;
    cin.getline(str, 100); // use getline() function to read a string from input stream
    vector<string> words;
    char *ptr;                // declare a ptr pointer
    ptr = strtok(str, " , "); // use strtok() function to separate string using comma (,) delimiter.
    cout << " \n Split string using strtok() function: " << endl;
    // use while loop to check ptr is not null
    while (ptr != NULL)
    {
        words.push_back(ptr);
        // cout << ptr  << endl; // print the string token
        ptr = strtok(NULL, " , ");
    }
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
    // cout << words.size() << endl;
    return 0;
}