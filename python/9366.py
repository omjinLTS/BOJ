for _ in range(int(input())):
    a,b,c=map(int, input().split())
    m = f"Case #{_+1}: "
    if max([a,b,c])*2-sum([a,b,c])>=0: m += 'invalid!'
    elif a==b==c: m += 'equilateral'
    elif a==b or b==c or a==c: m += 'isosceles'
    else: m += 'scalene'
    print(m)
