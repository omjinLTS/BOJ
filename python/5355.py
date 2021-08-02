oper = {'@':'*3', '%':'+5', '#':'-7'}
for _ in range(int(input())):
    c = input().split()
    n = c[0]
    for o in c[1:]:
        n = eval(str(n)+oper[o])
    print(format(n, '.2f'))