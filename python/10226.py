needle = int(input())
clock1 = [0]*360000
clock2 = [0]*360000
for n in map(int, input().split()):
    clock1[n]=1
for n in map(int, input().split()):
    clock2[n]=1

def getPi(p):
    pi, j = [0]*len(p), 0
    for i in range(1, len(p)):
        while j > 0 and p[i] != p[j]:
            j = pi[j-1]
        if p[i] == p[j]:
            j += 1
            pi[i] = j
    return pi
j = 0
clock1*=2
pi = getPi(clock2)
for i in range(720000):
    while j > 0 and clock1[i] != clock2[j]:
        j = pi[j-1]
    if clock1[i] == clock2[j]:
        if j == 359999:
            print('possible')
            exit(0)
        else:
            j+=1
print('impossible')
