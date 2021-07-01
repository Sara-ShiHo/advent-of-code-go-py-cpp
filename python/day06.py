with open('../data/day06.txt', 'r') as f:
    dat = [line.replace('\n', '') for line in f]
dat_str = " ".join(dat)
dat = dat_str.split("  ")
nqs = [len(set(line.replace(' ', ''))) for line in dat]
print(sum(nqs))


def find_intersect(ans):
    s = set("abcdefghijklmnopqrstuvwxyz")
    for a in ans:
        s = set(s).intersection(set(a))
    return s


nqs = [len(find_intersect(line.split(' '))) for line in dat]
print(sum(nqs))
