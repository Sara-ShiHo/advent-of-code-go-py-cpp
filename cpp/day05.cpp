#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int insertSorted(int arr[], int n, int key)
{
    int i;
    for (i = n - 1; (i >= 0 && arr[i] > key); i--)
        arr[i + 1] = arr[i];
    arr[i + 1] = key;
    return (n + 1);
}

int find_row(string ticket)
{
    float low_row = 0;
    float up_row = 127;
    for (char& ch : ticket.substr(0, 7))
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
    float low_row = 0;
    float up_row = 7;
    for (char& ch: ticket.substr(7))
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
    int seat;
    int n = 0;
    int seats[1000] = {};

    ifstream myfile ("../data/day05.txt");
    int max_seat = 0;
    if (myfile.is_open()) 
    {
        while ( getline (myfile,line) ) 
        {
            seat = find_seat(line);
            n = insertSorted(seats, n, seat);
            if (seat > max_seat)
            {
                max_seat = seat;
            }
        }
    }
    myfile.close();
    cout << "Part I :" << max_seat << "\n";

    // find which seat is non-consecutive (missing)
    int start_i = seats[0];
    int i = 0;
    while (i + start_i == seats[i])
    {
        i += 1;
    }
    cout << "Part II: " << i + start_i << "\n";

}
