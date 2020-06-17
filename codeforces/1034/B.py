import math
import sys
n, m = map(int, input().split())
if n > m:
    n, m = m, n
if n == 1:
    print(6 * (m // 6) + 2 * max(0, (m % 6) - 3))
elif n == 2:
    if m == 2:
        print(0)
    elif m in (1, 3, 7):
        print(n * m - 2)
    else:
        print(n * m)
else:
    print((n * m // 2) * 2)
