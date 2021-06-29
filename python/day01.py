"""
find the two entries that sum to 2020
and then multiply those two numbers together
"""

import numpy as np


def find_nums(target, a):
    nums = set(target - np.array(a)) & set(a)
    return nums


dat = [int(x) for x in open("../data/day01.txt").readlines()]

results1 = find_nums(2020, dat)
print("Part I:")
print(results1)
print(np.sum(list(results1)))
print(np.prod(list(results1)))
print()

for val in dat:
    results2 = find_nums(2020 - val, dat)
    if len(results2) > 0:
        results2.add(val)
        break

print("Part II:")
print(results2)
print(np.sum(list(results2)))
print(np.prod(list(results2)))
