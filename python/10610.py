n = input()
if '0' not in n or sum(map(int, [*n]))%3:
    print(-1)
    exit(0)
print(*sorted(n)[::-1],sep='')