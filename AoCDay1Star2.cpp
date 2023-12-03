#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <regex>
using namespace std;

//this is so
string replaceSubstring(const string& input, const string& search, const string& replace){
    regex pattern(search);
    string result = regex_replace(input, pattern, replace);
    return result;
}
//therre has to be a better way
void convern(string &word){
    word = replaceSubstring(word, "eight", "eightt");
    word = replaceSubstring(word, "two", "twoo");
    word = replaceSubstring(word, "seven", "sevenn");
    word = replaceSubstring(word, "one", "onee");
    word = replaceSubstring(word, "three", "threee");
    word = replaceSubstring(word, "five", "fivee");
    word = replaceSubstring(word, "nine", "ninee");
    word = replaceSubstring(word, "one", "1");
    word = replaceSubstring(word, "two", "2");
    word = replaceSubstring(word, "three", "3");
    word = replaceSubstring(word, "four", "4");
    word = replaceSubstring(word, "five", "5");
    word = replaceSubstring(word, "six", "6");
    word = replaceSubstring(word, "seven", "7");
    word = replaceSubstring(word, "eight", "8");
    word = replaceSubstring(word, "nine", "9");
}
int main(){
    ifstream inputFile("D1S1.txt");

    if(!inputFile.is_open()){
        cerr << "Error opening the file." << endl;
        return 1;
    }

    int sum = 0;
    string line;
    int con;
    int digitOnething = 0;
    int digitTwothing = 0;

    while(getline(inputFile, line)){
        cout << "Line: " << line << endl;
        convern(line);
        digitOnething = 0;
        digitTwothing = 0;
        for(char c : line){
            if(isdigit(c)){
               if(digitOnething == 0){
                    digitOnething = c - '0';
                }
               digitTwothing = c - '0';
            }
        }
        
        cout << "Digit One Digit Two: " << digitOnething << digitTwothing << endl;
        //digitOne,Two 
        con = (digitOnething * 10) + digitTwothing;
        cout <<"Con: " << con << endl;
        sum += con;
    }

    inputFile.close();

    cout << "Sum of first and last digits in each line: " << sum << endl;

    return 0;
}