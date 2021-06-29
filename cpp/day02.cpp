#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


int parse1(int lower, int upper, char target, string password)
{
    // The password policy indicates the lowest and highest number of times a
    // given letter must appear for the password to be valid.
    int count = 0;
    for (char& letter : password)
    {
        if (target == letter)
        {
            count += 1;
            if (count > upper)
            {
                return 0;
            }
        }
    }
    if (count < lower)
    {
        return 0;
    }
    return 1;
}

int parse2(int lower, int upper, char target, string password)
{
    // Each policy actually describes two positions in the password,
    // Toboggan Corporate Policies have no concept of "index zero"!
    int count = 0;
    if (password[lower - 1] == target)
    {
        count += 1;
    }
    if (password[upper - 1] == target)
    {
        count += 1;
    }
    if (count == 1){
        return 1;
    }
    return 0;
}

int main () {
    string line;
    int count1 = 0;
    int count2 = 0;
    int len = 0;
    ifstream myfile ("../data/day02.txt");
    if (myfile.is_open()) 
    {
        while ( getline (myfile, line) ) 
        {
            len += 1;
            string rang = line.substr(0, line.find(" "));
            int lower = stoi(rang.substr(0, rang.find("-")));
            int upper = stoi(rang.substr(rang.find("-") + 1));
        
            char target = line.substr(line.find(": ") - 1, 1)[0];
            string password = line.substr(line.find(": ") + 2);
//
            count1 += parse1(lower, upper, target, password);
            count2 += parse2(lower, upper, target, password);
        }
        myfile.close();
        cout << count1 << ' ' << len - count1 << '\n';
        cout << count2 << ' ' << len - count2 << '\n';
    }
    else cout << "Unable to open file"; 
}
