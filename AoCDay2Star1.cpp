#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int RED = 12;
const int GREEN = 13;
const int BLUE = 14;

bool isPossible(int redCount,int greenCount, int blueCount) {
    if(redCount > RED || greenCount > GREEN || blueCount > BLUE)
        return false;
    
    return true;
}

void parse(string s){

}

int main() {
    // Define the target cube counts

    // Open the input file
    ifstream inputFile("D2S1.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int sumOfPossibleGames = 0;
    int id;
    int reds, greens, blues;
    string info;


    // Read the games input
    string line;
    while(getline(inputFile, line)){
        
        for(char c: line){
            if(isdigit(c)){
                id = c - '0';
            }
            if(c!= ' ' && c!= ':' && c!= ',' && c!= ';'){
                info += c;
            }
            if(c == ';'){
                parse(info);
                info.clear();
        }
        parse(info);
        info.clear();
    }



    // Output the sum of possible game IDs
    cout << "Sum of possible game IDs: " << sumOfPossibleGames << endl;

    // Close the input file
    inputFile.close();

    return 0;
}
