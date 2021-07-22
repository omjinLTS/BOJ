from collections import deque

a, b, c = map(int, input().split())
m=sum([a, b, c])
visited = [[False]*m for _ in range(m)]
    
if m%3: print(0)
else: 
    q = deque()
    q.append((min(a, b, c), max(a, b, c)))
    visited[a][b] = True
    while q:
        a, b = q.popleft()
        c = m-a-b
        if a==b==c:
            print(1)
            exit(0)
        for na, nb in (a, b), (b, c), (a, c):
            if na > nb:
                na, nb = na-nb, 2*nb
            elif nb > na:
                na, nb = 2*na, nb-na
            else: continue
            nc = m-na-nb
            a = min(na, nb, nc)
            b = max(na, nb, nc)
            if not visited[a][b]:
                q.append((a, b))
                visited[a][b] = True
    print(0)