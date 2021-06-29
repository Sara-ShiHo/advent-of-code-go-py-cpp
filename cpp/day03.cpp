// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int find_trees(string dat [], int r, int d)
{
    int length = sizeof(dat[0]);
    int n_X = 0;
    int right_pos = r;
    int down_pos = d;

    while (down_pos < length)
    {
        string line = dat[down_pos];
        if (line[right_pos] == '#')
        {
            n_X += 1;
        }
        right_pos = (right_pos + r) % length;
        down_pos += d;
    }
    return n_X;
}

int main () {
    string line;
    int i = 0;
    string* dat = new string[500] {};

    ifstream myfile ("../data/day03.txt");
    if (myfile.is_open()) 
    {
        while ( getline (myfile,line) ) 
        {
            dat[i] = line;
            i += 1;
        }
        myfile.close();
        cout << find_trees(dat, 1, 1) << "\n";
        cout << find_trees(dat, 3, 1) << "\n";
        cout << find_trees(dat, 5, 1) << "\n";
        cout << find_trees(dat, 7, 1) << "\n";
        cout << find_trees(dat, 1, 2) << "\n";
    }
    else cout << "Unable to open file";
    return 0;
}