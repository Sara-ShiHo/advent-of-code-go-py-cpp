"""
find the three entries that sum to 2020
and then multiply those three numbers together
"""

import numpy as np


def find_nums(target_sum, a):
    nums = set(target_sum - np.array(a)) & set(a)
    return nums


dat = [int(x) for x in open("../data/day1.txt").readlines()]

for i in (2020 - np.array(dat)):
    results = find_nums(i, dat)
    if len(results) > 0:
        results.add(i)
        break
print(np.prod(list(results)))
