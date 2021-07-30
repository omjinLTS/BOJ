import sys
s = [sys.stdin.readline() for i in range(4)]

for l in s:
    low, up, num, space = 0, 0, 0, 0
    l = l[:-1]
    for c in l:
        if c.isalpha():
            if c.islower(): low += 1
            else: up += 1
        elif c.isdigit(): num+=1
        else: space+=1
    print(low, up, num, space)