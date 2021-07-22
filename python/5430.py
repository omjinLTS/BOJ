import sys
from collections import deque
input = sys.stdin.readline


for _ in range(int(input())):
    reversed = False
    fs = input().rstrip()
    n = int(input())
    inp = input()[1:-2]
    dq = deque(map(int, inp.split(',')) if n else inp)
    if fs.count('D') > n:
        print('error')
        continue
    for f in fs:
        if f=='R':
            reversed = not reversed
        else:
            if reversed:
                dq.pop()
            else:
                dq.popleft()
    if reversed:
        dq.reverse()
    print(str(dq)[6:-1].replace(' ',''))