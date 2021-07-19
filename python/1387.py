P, k = map(int, input().split())
prime = [i for i in range(k)]
prime[0], prime[1] = 0, 0
for i in range(2, k):
    if prime[i]:
        for j in range(i*i, k, i):
            prime[j] = 0
prime = [i for i in prime if i]
t=0
for p in prime:
    if P%p<1:
        t=1
        break
if t:
    print('BAD',p)
else:
    print('GOOD')