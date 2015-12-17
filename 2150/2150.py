# -*- coding: utf-8 -*-

import math

prime = []

def sieve(n):
    global prime
    prime = [True] * (n + 1)
    prime[0] = False
    prime[1] = False
    s = int(math.sqrt(n)) + 1
    for i in range(s):
        if not prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            prime[j] = False

def solve(n, p):
    global prime
    a = []
    cnt = n + 1
    while len(a) < p:
        if prime[cnt]:
            a.append(cnt)
        cnt += 1
    v = []
    for i in range(len(a)):
        for j in range(i, len(a)):
            v.append(a[i] + a[j])
    v.sort()
    return v[p - 1]

if __name__ == "__main__":
    sieve(200000)
    while True:
        (n, p) = map(int, input().split())
        if n == -1 and p == -1:
            break
        print(solve(n, p))
