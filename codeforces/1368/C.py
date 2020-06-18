import math
import sys
input = sys.stdin.readline
n = int(input())
points = [(0, -1), (-1, -1)]
for i in range(n):
    points.append((i - 1, i))
    points.append((i, i))
    points.append((i + 1, i))
points.append((n - 1, n))
points.append((n, n))
print(len(points))
print('\n'.join(map(lambda i : str(i[0]) + ' ' + str(i[1]), points)))

