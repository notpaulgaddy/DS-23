#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string.h>
#include <typeinfo>
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
    // string input;
    string input = "Here is an example of text justification. Hello my name is actually Bob."; // currently string, should
    vector<string> input_words;
    vector<string> res;

    vector<vector<string>> input_text; //vector of vector of words
    vector<vector<string>> output_text;
    // initializing variables
    int start, end;
    start = end = 0;
    char dl = ' ';

    while ((start = input.find_first_not_of(dl, end)) != string::npos)
    {
        end = input.find(dl, start);
        input_words.push_back(input.substr(start, end - start));
    }


    if(argc>0){
        input_words.clear();
        input_text.clear();
        std::ifstream input_file;
        input_file.open(argv[1]);
        std::string line;
        
        while (getline(input_file, line))
       {
            input_words.clear();
            std::istringstream ss_line(line);
            while(ss_line){
                std::string element;
                ss_line >> element;
                if(element.c_str() && !element.c_str()[0]) {}
                else    input_words.push_back(element);
            }
            input_text.push_back(input_words);

        }

    }
    

    for(int i=0;i<input_text.size();i++)
    {

        output_text.push_back(fullJustify(input_text[i],14));

    }


    // res = fullJustify(input_words, 14);
    std::string topBot(16, '-');
    cout << topBot << endl;
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << "|" << res[i] << "|" << endl;
    // }

    for(int i=0;i<output_text.size();i++){
        vector<string> res=output_text[i];
        
        for(int j=0;j<res.size();j++){
            cout<< "|" << res[j]<<"|"<<endl;
        }

    }

    cout << topBot << endl;
}