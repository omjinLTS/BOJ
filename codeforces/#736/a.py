def get_divisor(n):
    n = int(n)
    divisors = []
    divisors_back = [] 

    for i in range(1, int(n**(1/2)) + 1): 
        if (n % i == 0):            
            divisors.append(i)
            if (i != (n // i)): 
                divisors_back.append(n//i)

    return divisors + divisors_back[::-1]

for _ in range(int(input())):
    P = int(input())
    d = get_divisor(P)
    while(len(d)<3):
        P-=1
        d = get_divisor(P)
    print(d[1],d[2])
