import numpy as np


def find_row(ticket):
    low_row = 0
    up_row = 127
    for ch in ticket[0:6]:
        if ch == "F":
            up_row = up_row - round((up_row - low_row) / 2)
        elif ch == "B":
            low_row = low_row + round((up_row - low_row) / 2)

    if ticket[6] == "F":
        return(min(low_row, up_row))
    elif ticket[6] == "B":
        return(max(low_row, up_row))


def find_col(ticket):
    low_row = 0
    up_row = 7
    for ch in ticket[7:9]:
        if ch == "L":
            up_row = up_row - round((up_row - low_row) / 2)
        elif ch == "R":
            low_row = low_row + round((up_row - low_row) / 2)

    if ticket[9] == "L":
        return(min(low_row, up_row))
    elif ticket[9] == "R":
        return(max(low_row, up_row))


def find_seat(ticket):
    row = find_row(ticket)
    col = find_col(ticket)
    return row * 8 + col


with open('../data/day05.txt', 'r') as f:
    dat = [line.replace('\n', '') for line in f]

seats = [find_seat(ticket) for ticket in dat]
print(f'Part I: {max(seats)}')

# organize the filled seats into a matrix
d = matrix = [[np.nan] * 8 for i in range(128)]
seats = [(find_row(ticket), find_col(ticket)) for ticket in dat]
for r, c in seats:
    d[r][c] = 1

# parse through the non-existant beginning rows
begin_r = 0
while (begin_r < len(d)) and (np.nan in d[begin_r]):
    begin_r += 1

# start searching for my seat, starting from the real beginning row
my_r = begin_r
while (my_r < len(d)) and (np.nan not in d[my_r]):
    my_r += 1
r_pos = d[my_r].index(np.nan)
print(f'Part II: {my_r * 8 + r_pos}')
