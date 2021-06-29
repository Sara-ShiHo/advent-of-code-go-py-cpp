def OO_bounds(value, lower, upper):
    if (value < lower) | (value > upper):
        return False
    return True


def valid_dict(d):

    # years -----------------------
    byr = int(d['byr'])
    iyr = int(d['iyr'])
    eyr = int(d['eyr'])

    if not OO_bounds(byr, 1920, 2002):
        return False
    if not OO_bounds(iyr, 2010, 2020):
        return False
    if not OO_bounds(eyr, 2020, 2030):
        return False

    # physical -----------------------
    try:
        hgt = int(d['hgt'][:-2])
        hgt_unit = d['hgt'][-2:]
    except ValueError:
        return False

    if hgt_unit == 'cm':
        if not OO_bounds(hgt, 150, 193):
            return False
    elif hgt_unit == 'in':
        if not OO_bounds(hgt, 59, 76):
            return False
    else:
        return False

    hcl = d['hcl']
    ecl = d['ecl']
    nums = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    letters = ['a', 'b', 'c', 'd', 'e', 'f']

    if hcl[0] != '#':
        return False
    elif len(hcl) != 7:
        return False
    else:
        for c in hcl[1:]:
            if (c not in nums) & (c not in letters):
                return False

    if ecl not in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']:
        return False

    # ID -----------------------
    pid = d['pid']

    if len(pid) != 9:
        return False
    else:
        for c in pid:
            if c not in nums:
                return False
    print(byr, iyr, eyr, hcl, ecl, pid)
    return True


with open('../data/day04.txt', 'r') as f:
    dat = [line.replace('\n', '') for line in f]
dat.append('')

contents_s = ''
count = 0

for line in dat:
    if line == '':
        contents = contents_s.split(' ')
        contents_d = dict([info.split(':') for info in contents if (info != '') & ('cid' not in info)])

        if len(contents_d) == 7:
            if valid_dict(contents_d):
                count += 1

        contents_s = ''

    contents_s = contents_s + line + ' '

print(count)
