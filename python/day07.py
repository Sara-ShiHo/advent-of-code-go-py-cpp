import sys
sys.setrecursionlimit(1500)

with open('../data/day07.txt', 'r') as f:
    dat = [line.replace('\n', '') for line in f]


def convert_line(line):
    """ parse string and format into dict
    """
    line = line.replace(' bags', '')
    line = line.replace(' bag', '')
    line = line.replace('.', '')

    outer_color, inner = line.split(' contain ')
    inner_str = inner.split(', ')
    inner = [desc.split(' ', 1) for desc in inner_str]
    inner_colors = [desc[1] for desc in inner]

    if 'other' in inner_colors:
        inner_colors = []
    return outer_color, inner_colors


def has_gold(colors, rules_dict):
    """ recursively check all the colors and their colors
    """
    if len(colors) == 0:
        return 0
    else:
        color = colors[0]
        if color == 'shiny gold':
            return 1
        else:
            # add inner colors to queue
            return has_gold(rules_dict[color] + colors[1:], rules_dict)


# convert raw data into dictionary containing list of colors 
rules_dict = {}
for line in dat:
    line = convert_line(line)
    rules_dict[line[0]] = line[1]

results = [has_gold(colors, rules_dict) for colors in rules_dict.values()]
print(sum(results))


## Part II

def convert_line(line):
    
    line = line.replace(' bags', '')
    line = line.replace(' bag', '')
    line = line.replace('.', '')
    
    outer, inner = line.split(' contain ')
    inner = inner.split(', ')
    inner = [desc.split(' ', 1) for desc in inner]
        
    d = [(key, int(value)) for value, key in inner if key != 'other']

    return outer, d


def count_bags(colors):
    
    if len(colors) == 0:
        return 0
    else:
        color_pair = colors[0]
        color = color_pair[0]
        bags = color_pair[1]
        
        # sum the number of bags, the bags inside of the bags, and the rest of the uncounted bags
        return bags + bags * count_bags(datdict[color]) + count_bags(colors[1:])

# convert raw data into dictionary containing list of color-number pairs
datdict = {}
for line in dat:
    line = convert_line(line)
    datdict[line[0]] = line[1]
datdict

print(count_bags(datdict['shiny gold']))
