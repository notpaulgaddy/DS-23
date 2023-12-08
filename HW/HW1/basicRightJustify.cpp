#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
void rightJustify(std::vector<std::string> &lines)
{
    for (std::string &line : lines)
    {
        // Find the index of the first non-space character
        size_t first_non_space = line.find_first_not_of(" ");
        // Erase all characters before the first non-space character
        line.erase(0, first_non_space);
    }
}

void limitLineLength(std::vector<std::string> &lines, size_t max_length)
{
    for (std::string &line : lines)
    {
        if (line.length() > max_length)
        {
            line.erase(max_length);
        }
    }
}
// get the length of each line
// subtract the length of line from x

int main()
{
    std::vector<std::string> lines = {"    hello world", "    how are you", "    i am fine."};
    // std::vector<std::string> lines = {"Here is an example of text justification."};
    rightJustify(lines);
    limitLineLength(lines, 24);
    std::string topBot(24, '-');
    std::cout << topBot << endl;

    for (const std::string &line : lines)
    {
        string newLine = line;
        int lineLength = newLine.length();
        int diffLength = 24 - lineLength;
        int remainingSpaces = diffLength - 2;
        std::string theSpaces(remainingSpaces, ' ');
        // int extraSpace =
        //  std::cout << std::left << newLine << theSpaces << "|" << std::endl;
        std::cout << std::left << "|" << theSpaces << newLine << " |" << std::endl;
    }
    std::cout << topBot << endl;
    return 0;
}
