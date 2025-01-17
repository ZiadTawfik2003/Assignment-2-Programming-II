//------------------------------------------------------------------
// File:      problem 3.cpp                                        |
// Purpose:   revising & practicing C++ through problem solving.   |
// Author:    Osama Refaat Sayed.                                  |
// Section:   S21                                                  |
// ID:        20221015                                             |
// TA:        Rana Abdelkader                                      |
// Date:      25 Oct 2023                                          |
//------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string>final_result;


vector<string> split(string target, string delimiter)
{
    for (int i = 0; i < target.size(); ) {


        if (target.substr(i, delimiter.size()) == delimiter) {
            i += delimiter.size(); // Skip the delimiter
        }


        else {


            size_t pos = target.find(delimiter, i); // Find the next occurrence of the delimiter
            if (pos == string::npos) {
                // If delimiter is not found, get the rest of the string
                final_result.push_back(target.substr(i));
                break;  // Exit the loop
            }

            else {
                final_result.push_back(target.substr(i, pos - i));
                i = pos + delimiter.size();
            }


        }


    }
}


int main()
{
    cout<<"Enter the text you want it to be splitted\n";
    string target;
    getline(cin,target);
//----------------------------------------------------------

    cout<<"Enter the delimiter\n";
    string delimiter;
    getline(cin,delimiter);

//----------------------------------------------------------
    split(target,delimiter);

//----------------------------------------------------------

    for (int i = 0; i < final_result.size(); ++i) {
        cout<<final_result[i]<<"\n";
    }
//----------------------------------------------------------

    return 0;
}
