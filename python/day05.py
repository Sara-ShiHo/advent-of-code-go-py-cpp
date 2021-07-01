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

seats = [find_row(ticket) * 8 + find_col(ticket) for ticket in dat]
seats = sorted(seats)

# find which seat is non-consecutive (missing)
start_i = min(seats)
i = 0
while i + start_i == seats[i]:
    i += 1
print(f'Part II: {i + start_i}')
