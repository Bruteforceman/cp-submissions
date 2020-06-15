import math
import sys
n = int(input())
color = []
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    col = 0
    if abs(x1) % 2 == 0:
        col += 1
    if abs(y1) % 2 == 0:
        col += 2
    color.append(str(col + 1))
print('YES')
print('\n'.join(color))
