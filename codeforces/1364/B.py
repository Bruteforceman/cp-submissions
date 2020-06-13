import math
import sys
input = sys.stdin.readline
t = int(input())
result = []
for i in range(t):
    n = int(input())
    p = [int(_) for _ in input().split()]
    rem = [False] * n
    for i in range(1, n - 1):
        if (p[i + 1] - p[i]) * (p[i] - p[i - 1]) > 0:
            rem[i] = True
    result.append(str(n - sum(rem)))
    arr = []
    for i in range(n):
        if rem[i] == False:
            arr.append(p[i])
    result.append(' '.join(map(str, arr)))
print('\n'.join(result))
