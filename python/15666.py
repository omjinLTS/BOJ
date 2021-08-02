from itertools import *
a, b = map(int, input().split())
for a in sorted(set(combinations_with_replacement(sorted(set(map(int,input().split()))), b))):
    print(*a)