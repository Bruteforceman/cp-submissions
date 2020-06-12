import sys
import math
input = sys.stdin.readline
t = int(input())
for cs in range(t):
    n = int(input())
    a = [int(_) for _ in input().split()]
    b = [int(_) for _ in input().split()]
    pa = []
    pb = []
    for i in range(n):
        j = n - i - 1
        if i > j: break
        if i < j:
            p, q = a[i], a[j]
        elif i == j:
            p, q = a[i], -1
        if p > q:
            p, q = q, p
        pa.append((p, q))
    for i in range(n):
        j = n - i - 1
        if i > j: break
        if i < j:
            p, q = b[i], b[j]
        elif i == j:
            p, q = b[i], -1
        if p > q:
            p, q = q, p
        pb.append((p, q))
    pa.sort()
    pb.sort()
    ans = True
    for i in range(len(pa)):
        for j in range(2):
            if pa[i][j] != pb[i][j]:
                ans = False
    print('Yes' if ans else 'No')
