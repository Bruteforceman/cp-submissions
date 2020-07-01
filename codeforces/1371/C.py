import math
import sys
t = int(input())
for cs in range(t):
    a, b, n, m = map(int, input().split())
    if min(a, b) >= m and a + b >= n + m:
        print('Yes')
    else:
        print('No')
