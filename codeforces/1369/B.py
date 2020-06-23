import math
import sys
input = sys.stdin.readline
t = int(input())
result = []
for cs in range(t):
    n = int(input())
    s = input().strip()
    first = n
    last = -1
    for i in range(n):
        if s[i] == '0':
            last = i
        if s[i] == '1' and first == n:
            first = i
    if first < last:
        result.append(s[:first] + s[last:])
    else:
        result.append(s)
print('\n'.join(result))

