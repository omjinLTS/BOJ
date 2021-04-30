import sys
input = sys.stdin.readline
input()
points = list(map(int, input().split()))
sp = list(sorted(set(points)))
dic = {sp[i]:i for i in range(len(sp))}
print(*[dict[p] for p in points])