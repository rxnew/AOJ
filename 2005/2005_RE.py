# -*- coding: utf-8 -*-

# Warshall-Floyd Algorithm
def calc(d):
    global n
    for i in range(n):
        for j in range(n):
            for k in range(n):
                d[j][k] = min(d[j][k], d[j][i] + d[i][k])
    return d

def solve(d):
    global n, s, g1, g2
    res = float("inf")
    for i in range(n):
        res = min(res, d[s - 1][i] + d[i][g1 - 1] + d[i][g2 - 1])
    return res

if __name__ == "__main__":
    while True:
        (n, m, s, g1, g2) = map(int, input().split())
        if not (n or m or s or g1 or g2):
            break
        d = [[float("inf") for j in range(n)] for i in range(n)]
        for i in range(n):
            d[i][i] = 0
        for i in range(m):
            (b1, b2, c) = map(int, input().split())
            d[b1 - 1][b2 - 1] = c
        print(solve(calc(d)))
