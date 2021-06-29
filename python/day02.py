import numpy
import pandas as pd


def parse1(lower, upper, target, password):
    """
    The password policy indicates the lowest and highest number of times a
    given letter must appear for the password to be valid.
    For example, 1-3 a means that the password must contain a at
    least 1 time and at most 3 times.
    """

    count = 0
    for letter in password:
        if target == letter:
            count += 1
            if count > upper:
                return 0
    if count < lower:
        return 0
    return 1


def parse2(lower, upper, target, password):
    """
    Each policy actually describes two positions in the password,
    where 1 means the first character, 2 means the second character,
    and so on. (Be careful; Toboggan Corporate Policies have no concept of "index zero"!)
    Exactly one of these positions must contain the given letter.
    Other occurrences of the letter are irrelevant for the purposes of policy enforcement.
    """
    count = 0
    if (password[lower - 1] == target):
        count += 1
    if (password[upper - 1] == target):
        count += 1
    if count == 1:
        return 1
    return 0


dat = [x.split() for x in open("../data/day02.txt").readlines()]

valid_count1 = 0
valid_count2 = 0

for rang, letter, password in dat:

    lower, upper = rang.split('-')
    lower = int(lower)
    upper = int(upper)
    target = letter.replace(':', '')

    valid_count1 += parse1(lower, upper, target, password)
    valid_count2 += parse2(lower, upper, target, password)


print(valid_count1, len(dat) - valid_count1)
print(valid_count2, len(dat) - valid_count2)
