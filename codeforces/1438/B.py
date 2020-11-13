import sys
input = sys.stdin.readline
t = int(input())
for cs in range(t):
    n = int(input())
    b = [int(_) for _ in input().split()]
    t = {i : 0 for i in b}
    print('YES' if len(t) < n else 'NO')
