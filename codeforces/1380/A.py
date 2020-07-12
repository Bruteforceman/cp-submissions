import math
import sys
t = int(input())
for cs in range(t):
    n = int(input())
    a = [int(_) for _ in input().split()]
    opt = -1
    for i in range(1, n - 1):
        if a[i - 1] < a[i] and a[i] > a[i + 1]:
            opt = i
    if opt == -1:
        print('NO')
    else:
        print('YES')
        opt += 1
        print(opt - 1, opt, opt + 1)
