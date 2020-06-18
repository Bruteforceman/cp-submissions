import math
import sys
input = sys.stdin.readline
t = int(input())
result = []
for cs in range(t):
    a, b, n = map(int, input().split())
    cnt = 0
    while max(a, b) <= n:
        if a > b:
            a, b = b, a
        a += b
        cnt = cnt + 1
    result.append(cnt)
print('\n'.join(map(str, result)))
