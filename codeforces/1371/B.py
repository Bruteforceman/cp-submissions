import math
import sys
t = int(input())
for cs in range(t):
    n, r = map(int, input().split())
    if r < n:
        print((r * (r + 1)) // 2)
    else:
        print(1 + (n * (n - 1)) // 2)
