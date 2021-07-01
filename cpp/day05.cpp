#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <cfenv>
#pragma STDC FENV_ACCESS ON

using namespace std;

int find_row(string ticket)
{
    int low_row = 0;
    int up_row = 127;
    for (char& ch : ticket.substr(0, 6))
    {
        if (ch == 'F')
        {
            up_row = up_row - round((up_row - low_row) / 2);
        }  
        else if (ch == 'B')
        {
            low_row = low_row + round((up_row - low_row) / 2);
        }
    }
    if (ticket[6] == 'F')
    {
        return(min(low_row, up_row));
    }
    return(max(low_row, up_row));
}

int find_col(string ticket)
{
    int low_row = 0;
    int up_row = 7;
    for (char& ch: ticket.substr(7, 9))
    {
        if (ch == 'L')
        {
            up_row = up_row - round((up_row - low_row) / 2);
        }
        else if (ch == 'R')
        {
            low_row = low_row + round((up_row - low_row) / 2);
        }
    }
    if (ticket[9] == 'L')
    {
        return(min(low_row, up_row));
    }
    return(max(low_row, up_row));
}

int find_seat(string ticket)
{
    int row = find_row(ticket);
    int col = find_col(ticket);
    return row * 8 + col;
}

int main () {
    string line;
    map<string, string> m {};
    string contents = "";

    ifstream myfile ("../data/day05.txt");
    int max_seat = 0;
    if (myfile.is_open()) 
    {
        while ( getline (myfile,line) ) 
        {
            int seat = find_seat(line);
            if (seat > max_seat)
            {
                max_seat = seat;
            }
        }
    }
    myfile.close();
    cout << "Part I :" << max_seat << "\n";
}
