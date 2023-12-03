#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctype.h>
using namespace std;

int wordToNumber(const std::string& word) {
    map<string, int> wordToNumberMap = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    auto it = wordToNumberMap.find(word);
    return (it != wordToNumberMap.end()) ? it->second : 0;
}
int main(){
    ifstream inputFile("D1S1.txt");

    if(!inputFile.is_open()){
        cerr << "Error opening the file." << endl;
        return 1;
    }

    int sum = 0;
    string line;
    string digitOne;
    string digitTwo;
    string con;

    while(getline(inputFile, line)){
        digitOne.clear();
        digitTwo.clear();
        string word;
        for(char c : line){
            if(isdigit(c)){
                if(digitOne == ""){
                    digitOne = c;
                }
                digitTwo = c;
            }if(isalpha(c)){
                word+=c;
            }
            else if(!word.empty()){
                if(digitOne.empty()){
                    digitOne = wordToNumber(word);
                }
                digitTwo = wordToNumber(word);
                word.clear();
            }
        }
        cout << line << endl;
        cout << digitOne << digitTwo << endl;
        con = digitOne + digitTwo;
        sum += stoi(con);
    }

    inputFile.close();

    cout << "Sum of first and last digits in each line: " << sum << endl;

    return 0;
}