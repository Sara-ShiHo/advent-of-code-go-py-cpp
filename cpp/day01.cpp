// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main () {
    string line;
    set<int> dat;
    set<int> compare;

    ifstream myfile ("../data/day01.txt");
    if (myfile.is_open()) 
    {
        while ( getline (myfile,line) ) 
        {
            dat.insert(stoi(line));
            compare.insert(2020 - stoi(line));
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 

    set<int> intersect;
    std::set_intersection(dat.begin(), dat.end(), compare.begin(), compare.end(),
                          std::inserter(intersect, intersect.begin()));
    
    // print the set and product
    int product = 1;
    for (int i : intersect)
    {
        cout << i << ' ';
        product = product * i;
    }
    cout << "\n" << product << "\n";
    return 0;
}