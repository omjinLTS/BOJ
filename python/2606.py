from collections import deque

n = int(input())
nodes = int(input())
graph = [[] for _ in range(n+1)]
for _ in range(nodes):
    a, b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
visited = [False for i in range(n+1)]# visited == infected

#bfs
q = deque([1])
visited[1] = True
cnt=0
while q:
    v = q.popleft()
    for i in graph[v]:
        if not visited[i]:
            cnt += 1
            q.append(i)
            visited[i] = True
print(cnt)