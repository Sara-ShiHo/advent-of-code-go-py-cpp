// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int find_trees(string dat [], int down_length, int r, int d)
{
    int n_X = 0;
    int right_length = dat[0].length();
    int right_pos = r;
    int down_pos = d;
    while (down_pos < down_length)
    {
        string line = dat[down_pos];
        if (line[right_pos] == '#')
        {
            n_X += 1;
        }
        right_pos = (right_pos + r) % right_length;
        down_pos = down_pos + d;
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
            i++;
        }
        myfile.close();
        long product = 1;
        product = product * find_trees(dat, i, 1, 1);
        product = product * find_trees(dat, i, 3, 1);
        product = product * find_trees(dat, i, 5, 1);
        product = product * find_trees(dat, i, 7, 1);
        product = product * find_trees(dat, i, 1, 2);
        cout << product << "\n";
    }
    else cout << "Unable to open file";
    return 0;
}