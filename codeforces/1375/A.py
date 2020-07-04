import math
import sys
t = int(input())
for cs in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    for i in range(n):
        if i % 2 == 0:
            a[i] = abs(a[i])
        else:
            a[i] = -abs(a[i])
    print(' '.join(map(str, a)))
