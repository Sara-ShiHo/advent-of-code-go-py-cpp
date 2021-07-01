#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int find_intersect(set<string> dat)
{
    set<char> intersect;
    set<char> datSet;
    set<char> abc = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                     'h', 'i', 'j', 'k', 'l', 'm', 'n',
                     'o', 'p', 'q', 'r', 's', 't', 'u',
                     'v', 'w', 'x', 'y', 'z'};
    for (string s: dat)
    {
        for (char c: s)
        {
            datSet.insert(c);
        }

        std::set_intersection(datSet.begin(), datSet.end(),
                              abc.begin(), abc.end(),
                              std::inserter(intersect, intersect.begin()));
        datSet.clear();
        abc.clear();
        for (char c : intersect)
        {
            abc.insert(c);
        }
        intersect.clear();
    }
    return abc.size();
}

int main () {
    string line;
    string dat1;
    int i = 0;
    set<string> dat2;
    set<char> charSet;

    int count1 = 0;
    int count2 = 0;
    ifstream myfile ("../data/day06.txt");
    if (myfile.is_open()) 
    {
        while ( getline (myfile,line) ) 
        {
            if (line == "") 
            {
                for (char c: dat1)
                {
                    charSet.insert(c);
                }
                count1 += charSet.size();
                count2 += find_intersect(dat2);
    
                dat1 = "";
                dat2.clear();
                charSet.clear();
            }
            else
            {
                dat1 += line;
                dat2.insert(line);
                i += 1;
            }
        }
        for (char c: dat1)
        {
            charSet.insert(c);
        }
        count1 += charSet.size();
        count2 += find_intersect(dat2);
    }
    myfile.close();
    cout << "Part I: " << count1 << "\n";
    cout << "Part II: " << count2 << "\n";
}
