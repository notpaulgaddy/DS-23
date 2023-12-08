#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

void flushLeft(string inputFile, string outputFile, int width, vector<string> &textFromFile)
{
    for (string &line : textFromFile)
    {
        size_t first_non_space = line.find_first_not_of(" ");
        line.erase(0, first_non_space);
    }
}
void flushRight(string inputFile, string outputFile, int width, vector<string> &textFromFile)
{
    for (string &line : textFromFile)
    {
        size_t first_non_space = line.find_first_not_of(" ");
        line.erase(0, first_non_space);
    }
}
void limitLineLength(vector<string> &lines, size_t max_length)
{
    for (string &line : lines)
    {
        if (line.length() > max_length)
        {
            line.erase(max_length);
        }
    }
}

int main(int argc, char *argv[])
{
    string inputFile = argv[1];
    string outputFile = argv[2];
    string widthInput = argv[3];
    int width = stoi(widthInput); // turn the width into int
    string formatting = argv[4];
    vector<string> textFromFile; // vector for file data

    ifstream openFile(inputFile);
    string line;
    if (!openFile.good())
    {
        cerr << "Can't open " << inputFile << " to read.\n";
        exit(1);
    }
    while (openFile >> line)
    {
        getline(openFile, line);
        textFromFile.push_back(line);
    }

    openFile.close();

    if (formatting == "flush_left")
    {
        flushLeft(inputFile, outputFile, width, textFromFile);
        limitLineLength(textFromFile, width);
        string topBot(width, '-');
        cout << topBot << endl;
        for (const string &line : textFromFile)
        {
            string newLine = "|" + line;
            int lineLength = newLine.length();

            int diffLength = width - lineLength;
            int remainingSpaces = diffLength - 2;
            if (remainingSpaces <= 0)
            {
                remainingSpaces = 1;
            }
            string theSpaces(remainingSpaces, ' ');
            cout << newLine << theSpaces << " |" << endl;
        }
        cout << topBot << endl;
    }
    else if (formatting == "flush_right")
    {
        flushRight(inputFile, outputFile, width, textFromFile);
        limitLineLength(textFromFile, width);
        string topBot(width, '-');
        cout << "right" << endl;
        cout << topBot << endl;
        for (const string &line : textFromFile)
        {
            {
                string newLine = line;
                int lineLength = newLine.length();
                int diffLength = width - lineLength;
                int remainingSpaces = diffLength - 2;
                if (remainingSpaces <= 0)
                {
                    remainingSpaces = 1;
                }
                string theSpaces(remainingSpaces, ' ');
                cout << left << "|" << theSpaces << newLine << " |" << endl;
            }
            cout << topBot << endl;
        }
    }
    return 0;
}