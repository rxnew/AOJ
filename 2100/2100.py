# -*- coding: utf-8 -*-

for _ in range(int(input())):
    n = int(input())
    h = [int(i) for i in input().split()]
    d = [h[i] - h[i + 1] for i in range(n - 1)]
    d.append(0)
    d.sort()
    print(abs(d[0]), d[-1])
