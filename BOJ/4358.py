import sys
input = sys.stdin.readline

# function
def divide(x):
    return x/total_number

# input
trees = dict()
total_number = 0
while True:
    tree_name = input().strip()
    if tree_name == '':
        break
    
    else:
        total_number += 1
        if tree_name in trees:
            trees[tree_name] += 1
        else:
            trees[tree_name] = 1

sorted_trees = dict(sorted(trees.items()))

# print("%.4f\n".join(map(divide, sorted_trees.values())))

for tree, count in sorted_trees.items():
    print("%s %.4f" % (tree, count/total_number*100))