import sys
input = sys.stdin.readline
t = int(input())
res = []
for cs in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    ans = 1
    opt = 0
    for i in range(n):
        if a[i] <= i + 1:
            opt = i + 1
    res.append(str(ans + opt))
print('\n'.join(res))
