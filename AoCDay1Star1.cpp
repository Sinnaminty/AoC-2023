#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

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
        digitOne = "";
        digitTwo = "";
        for(char c : line){
            if(isdigit(c)){
                if(digitOne == ""){
                    digitOne = digitTwo = c;
                }
                digitTwo = c;
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