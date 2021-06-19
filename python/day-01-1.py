"""
find the two entries that sum to 2020
and then multiply those two numbers together
"""

import numpy as np

dat = [int(x) for x in open("../data/day01.txt").readlines()]

nums = set(2020 - np.array(dat)) & set(dat)
print(np.prod(list(nums)))
