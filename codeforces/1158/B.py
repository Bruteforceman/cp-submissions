import math
import sys
n, k = map(int, input().split())
a = [0] * n
side = (n - k) // 2
for i in range(side, n, side + 1):
    a[i] = 1
print(''.join(map(str, a)))
