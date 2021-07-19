for i in range(int(input())):
    if i:print()
    print(f'Scenario #{i+1}:')
    a,b,c=map(int, input().split())
    a,b,c=sorted([a,b,c])
    print(['no','yes'][a**2+b**2==c**2])