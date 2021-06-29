import numpy as np


def find_trees(dat, right, down):
    length = len(dat[0])
    n_X = 0
    right_pos = right
    down_pos = down

    while down_pos < len(dat):
        line = dat[down_pos]

        if line[right_pos] == "#":
            n_X += 1

        right_pos = (right_pos + right) % length
        down_pos += down

    return n_X


with open('../data/day03.txt', 'r') as f:
    dat = [line.replace('\n', '') for line in f]

result1 = find_trees(dat.copy(), 1, 1)
result2 = find_trees(dat.copy(), 3, 1)
result3 = find_trees(dat.copy(), 5, 1)
result4 = find_trees(dat.copy(), 7, 1)
result5 = find_trees(dat.copy(), 1, 2)
print(result1 * result2 * result3 * result4 * result5)
