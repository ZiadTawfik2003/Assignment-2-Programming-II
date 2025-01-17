//------------------------------------------------------------------
// File:      problem 12.cpp                                       |
// Purpose:   revising & practicing C++ through problem solving.   |
// Author:    Osama Refaat Sayed.                                  |
// Section:   S21                                                  |
// ID:        20221015                                             |
// TA:        Rana Abdelkader                                      |
// Date:      25 Oct 2023                                          |
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
int main() {
    // list of phishing keywords and its points value
    map<string, int> phishingKeywords = {
            {"PayPal", 3},
            {"Congratulations", 1},
            {"Microsoft", 3},
            {"Urgent", 3},
            {"compromised", 3},
            {"Limited", 1},
            {"below", 1},
            {"Discount", 1},
            {"Apple", 3},
            {"Verify", 3},
            {"Free", 1},
            {"suspended", 3},
            {"Nigerian", 2},
            {"Alert", 3},
            {"IRS", 3},
            {"Win", 1},
            {"Incredible", 1},
            {"Update", 3},
            {"Security", 3},
            {"now", 1},
            {"Credit", 3},
            {"Bank of America", 3},
            {"Double your", 1},
            {"Free", 2},
            {"cash", 1},
            {"Amazon", 3},
            {"detected", 3},
            {"Guaranteed", 1},
            {"Google", 3},
            {"Click", 1}
    };
//----------------------------------------------------------

    string filename = "sample.txt";
    ifstream file(filename);
//----------------------------------------------------------

    if (!file.is_open()) {
        //using cerr to print error outputs
        cerr << "Error: the file can not be opened." << endl;
        return 1;
    }

    string word;
    map<string, int> keywordCounts; // pair consist of the word and its counter
    int totalPoints = 0; //initialize
// ----------------------------------------------------------

    // reading every word in the file
    while (file >> word) {
        if (phishingKeywords.find(word) != phishingKeywords.end()) {
            totalPoints += phishingKeywords[word];
            keywordCounts[word]++;
        }
    }
//----------------------------------------------------------

    cout << "Phishing Keyword | Occurrences | Points" << endl;
    for (const auto& pair : keywordCounts) {
        cout << pair.first << " | " << pair.second << " | " << pair.second * phishingKeywords[pair.first] << endl;
    }

    cout << "Total Points: " << totalPoints << endl;
//----------------------------------------------------------

    file.close(); // close the file before ending the program
    return 0;
}
