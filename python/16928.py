from collections import deque


N, M = map(int, input().split())
board = [i for i in range(101)]
dice = [-1]*101
for _ in range(N):
    x, y = map(int, input().split())
    board[x] = y
for _ in range(M):
    u, v = map(int, input().split())
    board[u] = v

def bfs():
    q = deque()
    q.append(1)
    dice[1] = 0
    while(q):
        idx = q.popleft()
        for i in range(1, 7):#주사위를 굴려서
            nidx = idx + i
            if nidx>100:
                break
            nboard = board[nidx]#굴린 주사위로 가는곳(뱀 또는 사다리가 있으면 변동)
            if dice[nboard] == -1 or dice[nboard] > dice[idx] + 1:#그곳이 간 적이 없거나 지금 가는게 더 빠르면
                q.append(nboard)
                dice[nboard] = dice[idx]+1
bfs()
print(dice[100])