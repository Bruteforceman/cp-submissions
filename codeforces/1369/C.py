import math
import sys
input = sys.stdin.readline
t = int(input())
result = []
for cs in range(t):
    n, k = map(int, input().split())
    a = sorted([int(_) for _ in input().split()], reverse=True)
    w = sorted([int(_) for _ in input().split()])
    answer = 0
    for i in range(k):
        if w[i] == 1:
            answer += a[i] + a[i]
        else: 
            answer += a[i]
    cur = k
    for i in range(k):
        w[i] -= 1
        if w[i] > 0:
            answer += a[cur + w[i] - 1]
            cur += w[i]
    result.append(answer) 
print('\n'.join(map(str, result)))
