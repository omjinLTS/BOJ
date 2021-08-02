from itertools import *
a,b=map(int,input().split())
for c in sorted(set(permutations([*map(int, input().split())], b))):
    print(*c)