import math
import sys
input = sys.stdin.readline
t = int(input())
result = []
for cs in range(t):
    n, m = map(int, input().split())
    a = [[] for _ in range(n)]
    for i in range(n):
        a[i] = [int(_) for _ in input().split()]
    def inside(x, y):
        return (0 <= x and x < n) and (0 <= y and y < m)
    good = True
    for x in range(n):
        for y in range(m):
            cnt = 0
            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                if inside(x + dx, y + dy):
                    cnt += 1
            if a[x][y] > cnt:
                good = False
            a[x][y] = cnt
    if good:
        result.append('YES')
        for i in a:
            result.append(' '.join(map(str, i)))
    else:
        result.append('NO')
print('\n'.join(result))
