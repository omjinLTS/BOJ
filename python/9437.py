while 1:
    i = input()
    if i == '0':
        exit(0)
    n, p = map(int, i.split())
    page = [[] for i in range(n//4)]
    pc = 1
    for i in range(n//4):
        page[i] = [pc, pc + 1, n-pc, n-pc+1]
        pc+=2
    for pg in page:
        if p in pg:
            pg.remove(p)
            print(*pg)
            break 