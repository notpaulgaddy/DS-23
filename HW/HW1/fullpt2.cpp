#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getSpaces(int n)
{
    string emptyString = "";
    for (int i = 0; i < n; i++)
    {
        emptyString += " ";
    }
    return emptyString;
}

string getLine(vector<string> &textFromFile, int startPos, int endPos, int amountOfLetters, int lineWidth)
{
    string newFileData = textFromFile[startPos];
    int spaces = lineWidth - amountOfLetters;
    if (startPos == endPos)
    {
        newFileData = newFileData + getSpaces(spaces);
        return newFileData;
    }
    int theDifference = endPos - startPos;
    int amtOfSpaces = spaces / theDifference;
    int lastFewSpaces = spaces % theDifference;
    string theFirstSpace = getSpaces(amtOfSpaces);
    string theSecondSpace = theFirstSpace + " ";
    for (int i = 0; i < theDifference; i++)
    {
        newFileData = newFileData + (i < lastFewSpaces ? theSecondSpace : theFirstSpace) + textFromFile[startPos + 1 + i]; // help from roommate mike
    }
    return newFileData;
}

vector<string> fullJustify(vector<string> &textFromFile, int lineWidth)
{
    int i = 0;
    int j = 0;
    int counter = 0;
    vector<string> newFileData;
    while (i < textFromFile.size() && j < textFromFile.size())
    {
        int len = textFromFile[j].length();
        counter = counter + len;
        if (lineWidth < counter + j - i)
        {
            counter = counter - len;
            newFileData.push_back(getLine(textFromFile, i, j - 1, counter, lineWidth));
            i = j;
            counter = 0;
        }
        else
        {
            j++;
        }
    }
    if (counter)
    {
        string last = textFromFile[i];
        for (int x = i + 1; x < j; x++)
        {
            last = last + " " + textFromFile[x];
        }
        last = last + getSpaces(lineWidth - last.size());
        newFileData.push_back(last);
    }
    return newFileData;
}

int main()
{
    vector<string> textFromFile = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> lines;
    lines = fullJustify(textFromFile, 16);
    string emptyString = "";
    string topBot(20, '-');
    cout << topBot << endl;
    for (int i = 0; i < 16; i++)
    {
        emptyString = emptyString + char(i % 10 + '0');
    }
    for (string x : lines)
    {
        cout << "| " << x << " |" << endl;
    }
    cout << topBot << endl;
    return 0;
}