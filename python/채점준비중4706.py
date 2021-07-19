a, b = map(float, input().split())
while a:
    print(format((1-(b**2)/(a**2))**0.5, '.3f'))
    a, b = map(float, input().split())