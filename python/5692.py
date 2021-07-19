n = input()
def factorial(i):
    return 1 if i<2 else i*factorial(i-1)

while n!='0':
    n = n[::-1]
    s = 0
    for i in range(len(n)):
        s += int(n[i])*factorial(i+1)
    print(s)
    n = input()