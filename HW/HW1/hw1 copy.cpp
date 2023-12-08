#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<string> fullJustify(vector<string> &input_words, int length)
{
    vector<string> result;
    int i, j;
    for (i = 0; i < input_words.size(); i = j)
    {
        int width = 0;
        for (j = i; j < input_words.size() && width + input_words[j].size() + j - i <= length; j++)
        {
            width += input_words[j].size();
        }
        int space = 1;
        int extra = 0;
        if (j - i != 1 && j != input_words.size())
        {
            space = (length - width) / (j - i - 1);
            extra = (length - width) % (j - i - 1);
        }
        string line(input_words[i]);
        for (int k = i + 1; k < j; k++)
        {
            line += string(space, ' ');
            if (extra-- > 0)
            {
                line += " ";
            }
            line += input_words[k];
        }
        int x = line.size();
        line += string(length - x, ' ');
        result.push_back(line);
    }
    return result;
}

int main(int argc, char *argv[])
{
    string input = "Here is an example of text justification. Hello my name is actually Bob."; // currently string, should
    vector<string> input_words;
    vector<string> res;
    string inputFile = argv[1];
    string outputFile = argv[2];
    string widthInput = argv[3];
    int width = stoi(widthInput); // turn the width into int
    int newWidth = width - 2;
    string formatting = argv[4];
    vector<string> textFromFile; // vector for file data

    std::ifstream openFile(inputFile);
    if (!openFile.good())
    {
        std::cerr << "Can't open " << inputFile << " to read.\n";
        exit(1);
    } // check for error opening file

    int start, end;
    start = end = 0;
    char dl = ' ';

    while ((start = input.find_first_not_of(dl, end)) != string::npos)
    {
        end = input.find(dl, start);
        input_words.push_back(input.substr(start, end - start));
    }
    if (formatting == "flush_left")
    {
        res = fullJustify(input_words, newWidth);
        std::string topBot(width, '-');
        cout << topBot << endl;
        for (int i = 0; i < res.size(); i++)
        {
            cout << "|" << res[i] << "|" << endl;
        }
        cout << topBot << endl;
    }
}