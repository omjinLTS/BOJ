N = int(input())
M = int(input())
if M:brokenButtons = input().split()
cnt = abs(N-100)
for i in range(1000001):
    broken = 0
    if M:
        for s in str(i): 
            if s in brokenButtons: broken = 1; break
    if not broken: cnt = min(cnt, len(str(i))+abs(N-i))
print(cnt)