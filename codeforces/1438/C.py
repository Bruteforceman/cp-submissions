import sys
input = sys.stdin.readline
t = int(input())
for cs in range(t):
    n, m = map(int, input().split())
    a = [[] for _ in range(n)]
    for i in range(n):
        a[i] = [int(_) for _ in input().split()]
        for j in range(m):
            if a[i][j] % 2 != (i + j) % 2:
                a[i][j] += 1
    print('\n'.join([' '.join(map(str, a[_])) for _ in range(n)]))

