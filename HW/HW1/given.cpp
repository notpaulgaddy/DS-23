#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// returns the words parsed from the filepath
std::vector<std::string> getWords(const char *filepath)
{
    // opening the file
    std::ifstream inputFile(filepath, std::ios::in);

    // reading in the words
    std::vector<std::string> words;
    std::string word;
    while (inputFile >> word)
    {
        words.emplace_back(word);
    }

    // returning the words
    return words;
}

void writeOutput(const char *filepath,
                 const std::vector<std::string> &buffer,
                 const int textWidth)
{
    // opening the file
    std::ofstream outputFile(filepath, std::ios::out);

    // top
    for (int i = 0; i < textWidth + 4; ++i)
    {
        outputFile << '-';
    }
    outputFile << '\n';

    // content
    for (const std::string &line : buffer)
    {
        outputFile << "| " << line << " |\n";
    }

    // bottom
    for (int i = 0; i < textWidth + 4; ++i)
    {
        outputFile << '-';
    }
    outputFile << '\n';
}

// packs text left
std::vector<std::string> packLeft(const std::vector<std::string> &words,
                                  const int textWidth)
{
    // declaring buffer
    std::vector<std::string> buffer;

    std::string line(textWidth, ' ');
    int writeCol = 0;
    for (const std::string &word : words)
    {
        // check if word will fit in
        if (textWidth - writeCol - 1 < static_cast<int>(word.length()))
        {
            // word it too large
            buffer.emplace_back(line);
            std::fill(line.begin(), line.end(), ' ');
            writeCol = 0;
        }

        // writing word
        for (const char ch : word)
        {
            line[writeCol] = ch;
            ++writeCol;
        }

        // updating write head
        if (writeCol >= textWidth - 1)
        {
            buffer.emplace_back(line);
            std::fill(line.begin(), line.end(), ' ');
            writeCol = 0;
        }
        else
        {
            ++writeCol;
        }
    }

    // last row
    if (writeCol != 0)
    {
        buffer.emplace_back(line);
    }

    // returning buffer
    return buffer;
}

// shifts text to the right
void shiftRight(std::string &line)
{
    const int length = static_cast<int>(line.length());

    // counting number of spaces
    int spaceCount = 0;
    for (int i = length - 1; i >= 0; --i)
    {
        if (line[i] == ' ')
        {
            ++spaceCount;
        }
        else
        {
            break;
        }
    }

    // rotating by the space count
    std::rotate(line.begin(), line.end() - spaceCount, line.end());
}

// packs text right
std::vector<std::string> packRight(const std::vector<std::string> &words,
                                   const int textWidth)
{
    // declaring buffer
    std::vector<std::string> buffer;

    std::string line(textWidth, ' ');
    int writeCol = 0;
    for (const std::string &word : words)
    {
        // check if word will fit in
        if (textWidth - writeCol - 1 < static_cast<int>(word.length()))
        {
            // word it too large
            shiftRight(line);
            buffer.emplace_back(line);
            std::fill(line.begin(), line.end(), ' ');
            writeCol = 0;
        }

        // writing word
        for (const char ch : word)
        {
            line[writeCol] = ch;
            ++writeCol;
        }

        // updating write head
        if (writeCol >= textWidth - 1)
        {
            shiftRight(line);
            buffer.emplace_back(line);
            std::fill(line.begin(), line.end(), ' ');
            writeCol = 0;
        }
        else
        {
            ++writeCol;
        }
    }

    // last row
    if (writeCol != 0)
    {
        shiftRight(line);
        buffer.emplace_back(line);
    }

    // returning buffer
    return buffer;
}

// justifies text
void shiftJustify(std::string &line,
                  const int textWidth,
                  const std::vector<std::string> &temp)
{
    if (temp.size() == 1)
    {
        // no justification needed
        line = temp[0] + std::string(textWidth -
                                         static_cast<int>(temp[0].length()),
                                     ' ');
        return;
    }

    // finding number of characters
    int numChars = 0;
    for (const std::string &word : temp)
    {
        numChars += static_cast<int>(word.length());
    }

    // number of spaces
    const int numSpaces = textWidth - numChars;

    // number of space segments
    const int numSpaceSegments = static_cast<int>(temp.size()) - 1;

    // constructing space array
    const int eachSpaceSegmentLength = numSpaces / numSpaceSegments;
    std::vector<int> spaceLengths(numSpaceSegments, eachSpaceSegmentLength);

    // justifying space lengths
    {
        int total = eachSpaceSegmentLength * numSpaceSegments;
        int i = 0;
        while (total != numSpaces)
        {
            ++spaceLengths[i];
            ++total;
            ++i;
        }
    }

    // filling string
    int i = 0;
    for (const std::string &word : temp)
    {
        line += word;
        if (i < static_cast<int>(spaceLengths.size()))
        {
            line += std::string(spaceLengths[i], ' ');
            ++i;
        }
    }
}

// packs text justify
std::vector<std::string> packJustify(const std::vector<std::string> &words,
                                     const int textWidth)
{
    // declaring buffer
    std::vector<std::string> buffer;

    std::vector<std::string> temp;
    int writeCol = 0;
    for (const std::string &word : words)
    {
        // check if word will fit in
        if (textWidth - writeCol - 1 < static_cast<int>(word.length()))
        {
            // word it too large
            std::string line;
            shiftJustify(line, textWidth, temp);
            buffer.emplace_back(line);
            temp.clear();
            writeCol = 0;
        }

        // writing word
        temp.emplace_back(word);
        for (const char ch : word)
        {
            ++writeCol;
        }

        // updating write head
        if (writeCol >= textWidth - 1)
        {
            std::string line;
            shiftJustify(line, textWidth, temp);
            buffer.emplace_back(line);
            temp.clear();
            writeCol = 0;
        }
        else
        {
            ++writeCol;
        }
    }

    // last row
    if (writeCol != 0)
    {
        std::string line;
        shiftJustify(line, textWidth, temp);
        buffer.emplace_back(line);
    }

    // returning buffer
    return buffer;
}

// packs the text
std::vector<std::string> pack(const std::vector<std::string> &words,
                              const char mode,
                              const int textWidth)
{
    switch (mode)
    {
    case 'L':
        return packLeft(words, textWidth);
    case 'R':
        return packRight(words, textWidth);
    case 'J':
        return packJustify(words, textWidth);
    }
}

// entry point
int main(int argc, char **argv)
{
    // reading command line arguments
    const char *inputFilepath = argv[1];
    const int textWidth = atoi(argv[2]);
    const char mode = argv[3][0];
    const char *outputFilepath = argv[4];

    // getting the words
    const std::vector<std::string> words = getWords(inputFilepath);

    // packing text
    const std::vector<std::string> buffer = pack(words, mode, textWidth);

    // writing packed output
    writeOutput(outputFilepath, buffer, textWidth);

    // end of program
    return 0;
}
