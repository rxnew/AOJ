while True:
    n, r = map(int, input().split())
    if not (n or r): break
    d = [n - i for i in range(n)]
    for i in range(r):
        p, c = map(int, input().split()); p -= 1
        d = d[p:p + c] + d[:p] + d[p + c:]
    print(d[0])
