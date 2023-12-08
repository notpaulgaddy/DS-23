#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string.h>
#include <typeinfo>
using namespace std;

vector<string> fullJustify(vector<string> &input_words, int length){
    vector<string> result;//vector to contain the result
    int i;
    int j;
    for (i = 0; i < input_words.size(); i = j){
        int width = 0;
        int space = 1;
        int extra = 0;
        for (j = i; j < input_words.size() && width + input_words[j].size() + j - i <= length; j++){//size comparisons
            width += input_words[j].size(); //calculate necessary width
        }
        if (j - i != 1 && j != input_words.size()){
            space = (length - width) / (j - i - 1);//calculate current space
            extra = (length - width) % (j - i - 1);//calculate extra space
        }
        string line(input_words[i]);
        for (int k = i + 1; k < j; k++){
            line += string(space, ' ');//add the amount of spaces to the line
            if (extra-- > 0){//check if theres enough space
                line = line+" ";
            }
            line += input_words[k];//add each new word to the line
        }
        int x = line.size();
        line += string(length - x, ' ');
        result.push_back(line);//append the new line
    }
    return result;
}

vector<string> leftJustify(vector<string> &textFromFile, int width){
    int c = 0;
    string line = "";
    int currentCount = 0;
    int nextCount = 0;
    string curLine = "";//the current line string
    int pos = 0;
    int i;
    int j;
    vector<string> result;
    for (int i = 0; i < textFromFile.size(); i++){
        for (int j = 0; j < textFromFile[i].size(); j++){
            c = c+1;
        }
        line += textFromFile[i];
        c = c+1;
    }
    c = c-1;
    if (c < width){//check if there's enough space left on the line
        int diff = width - c;//find the difference of spaces
        for (int k = 0; k < diff; k++){
            line = line+" ";
        }
        result.push_back(line);//if not, add it to the next vector element
        return result;
    }
    for (int i = 0; i < textFromFile.size(); i = j){
        nextCount = 0;//set the count of the next line
        currentCount = 0;
        string curLine = "";
        for (j = i; j < textFromFile.size(); j++){
            nextCount += textFromFile[j].size();//calculate length of next line
            if (nextCount <= width){//if less than or equal to the width
                if (nextCount == width){//and if its equal to the width
                    curLine += textFromFile[j];//add the current line
                    j = j+1;
                    break;
                }else{
                    curLine += textFromFile[j] + " ";
                    nextCount += 1;
                    currentCount = nextCount;
                    if (j == textFromFile.size() - 1){
                        int spaces = width - currentCount;
                        for (int k = 0; k < spaces; k++){
                            curLine = curLine+" ";
                        }
                    }
                }
            }else{
                int spaces = width - currentCount;
                for (int k = 0; k < spaces; k++){
                    curLine += " ";//add a space to the current line
                }
                if(textFromFile[j].size()>width){
                    result.push_back(curLine);//append the current corrected line to the 
                    int linediv=textFromFile[j].size()/width;
                    int rem=textFromFile[j].size()%width;
                    int st=0;
                    string bigLine="";
                    for(int m=0;m<linediv;m++){
                        bigLine=textFromFile[j].substr(st,width);
                        result.push_back(bigLine);
                        st+=width;
                    }
                    curLine=textFromFile[j].substr(st,rem);
                    currentCount=rem;
                    nextCount=rem;
                    if(j==textFromFile.size() - 1){
                        int spaces=width-rem;
                        for(int k=0;k<spaces;k++){
                            curLine+=" ";
                        }
                    } else{
                        curLine+=" ";
                        currentCount+=1;
                        nextCount+=1;
                    }
                    continue;
                }
                break;
            }
        }
        result.push_back(curLine);//then add the data to the result
    }
    return result;
}

vector<string> rightJustify(vector<string> &textFromFile, int width){//this function is basically the same as left but in reverse
    int c = 0;
    string line = "";
    vector<string> result;
    int currentCount = 0;
    int nextCount = 0;
    string curLine = "";
    int pos = 0;
    int i;
    int j;
    for (int i = 0; i < textFromFile.size(); i++){
        for (int j = 0; j < textFromFile[i].size(); j++){
            c += 1;
        }
        line = " " + textFromFile[i];
        c = c+1;
    }
    c = c-1;
    if (c < width){
        int diff = width - c;
        string rightalign=" ";
        for (int k = 0; k < diff; k++){
            rightalign += " ";
        }
        line=rightalign+line;
        result.push_back(line);
        return result;
    }
    for (int i = 0; i < textFromFile.size(); i = j){
        nextCount = 0;
        currentCount = 0;
        string curLine = "";
        for (j = i; j < textFromFile.size(); j++){
            nextCount += textFromFile[j].size();
            if (nextCount <= width){
                if (nextCount == width){
                    curLine = curLine + " " + textFromFile[j];
                    j = j+1;
                    break;
                }else{
                    curLine =" "+curLine+ textFromFile[j];
                    nextCount += 1;
                    currentCount = nextCount;
                    if (j == textFromFile.size() - 1){
                        string rightalign="";
                        int spaces = width - currentCount;
                        for (int k = 0; k < spaces; k++){
                            rightalign += " ";
                        }
                        curLine=rightalign+curLine;
                    }
                }
            }else{
                int spaces = width - currentCount;
                string rightalign="";
                for (int k = 0; k < spaces; k++) {
                    rightalign += " ";
                }
                curLine=rightalign+curLine;
                if(textFromFile[j].size()>width){
                    result.push_back(curLine);
                    int linediv=textFromFile[j].size()/width;
                    int rem=textFromFile[j].size()%width;
                    int st=0;
                    string bigLine="";
                    for(int m=0;m<linediv;m++){
                        bigLine=textFromFile[j].substr(st,width);
                        result.push_back(bigLine);
                        st = st+width;
                    }
                    curLine=textFromFile[j].substr(st,rem);
                    currentCount=rem;
                    nextCount=rem;
                    if(j==textFromFile.size() - 1){
                        int spaces=width-rem;
                        string rightalign="";
                        for(int k=0;k<spaces;k++){
                            rightalign+=" ";
                        }
                        curLine=rightalign+curLine;
                    }else{
                        curLine=" "+curLine;
                        currentCount+=1;
                        nextCount+=1;
                    }
                    continue;
                }
                break;
            }
        }
        result.push_back(curLine);//then append the new line 
    }
    return result;
}

int main(int argc, char *argv[]){
    // string input;
    string input = "Here is an example of text justification. Hello my name is actually Bob."; 
    vector<string> input_words;
    vector<string> res;
    vector<vector<string> > input_text; // vector of vector of words
    vector<vector<string> > output_text;
    // initializing variables
    string outputToFile="";
    int start, end;
    start = end = 0;
    char dl = ' ';
    while ((start = input.find_first_not_of(dl, end)) != string::npos){
        end = input.find(dl, start);
        input_words.push_back(input.substr(start, end - start));
    }
    if (argc > 0)
    {
        input_words.clear();
        input_text.clear();
        ifstream input_file;
        input_file.open(argv[1]);
        string line;
        while (getline(input_file, line))
        {
            input_words.clear();
            istringstream ss_line(line);
            while (ss_line)
            {
                string element;
                ss_line >> element;
                if(line!="\n"){
                    input_words.push_back(element);
                }
                // if (line.size() == 0 || line=="\n"){
                //     continue;
                // }            
            
                // if (element.c_str() && !element.c_str()[0]){
                // }
                // else
                //     input_words.push_back(element);
            }
            input_text.push_back(input_words);
        }
    }

    for (int i = 0; i < input_text.size(); i++){
        input_words.erase(std::remove(input_words.begin(), input_words.end(), "\n"), input_words.end());
        if (strcmp(argv[4], "full_justify") == 0){
            output_text.push_back(fullJustify(input_text[i], atoi(argv[3])));
        }
        else if (strcmp(argv[4], "flush_right") == 0){
            output_text.push_back(rightJustify(input_text[i], atoi(argv[3])));
        }
        else if (strcmp(argv[4], "flush_left") == 0){
            output_text.push_back(leftJustify(input_text[i], atoi(argv[3])));
        }
    }
    string topBot(stoi(argv[3])+4, '-');//added 4 to account for the 2 spaces and 2 |'s
    outputToFile+=topBot+"\n";
    std::cout << topBot << endl;
    for (int i = 0; i < output_text.size(); i++){
        vector<string> res = output_text[i];
        for (int j = 0; j < res.size(); j++){
            std::cout << "| " << res[j] << " |" << endl;
            outputToFile+="| "+res[j]+" |"+"\n";
        }
    }

    std::cout << topBot << endl;
    outputToFile+=topBot;

    ofstream out(argv[2]);
    out << outputToFile;
    out.close();
    return 0;
}