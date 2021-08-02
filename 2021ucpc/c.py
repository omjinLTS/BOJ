a, d, k = map(int, input().split())
i, d, k = a, d/100, k/100
p = [1, d]
result = a*d
while p[1] != 1:
    a+=i
    p = [p[0]*(1-p[1]), p[1]*(1+k)]
    p[1] = min(1, p[1])
    result += a*p[0]*p[1]
print(format(result, '.7f'))