# -*- coding: utf-8 -*-

def get(v):
    sum = 0
    for var in v:
        sum += var
    a = [0] * (sum + 1)
    for i in range(len(v)):
        sum = 0
        for j in range(i, len(v)):
            sum += v[j]
            a[sum] += 1
    return a

def solve(h, w):
    a, b = get(h), get(w)
    result = 0
    for var1, var2 in zip(a, b):
        result += var1 * var2
    return result

if __name__ == "__main__":
    while True:
        (n, m) = map(int, input().split())
        if n == 0 and m == 0:
            break
        h = [int(input()) for i in range(n)]
        w = [int(input()) for i in range(m)]
        print(solve(h, w))
