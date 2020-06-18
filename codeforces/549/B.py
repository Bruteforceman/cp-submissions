import math
import sys
input = sys.stdin.readline
n = int(input())
a = [[] for _ in range(n)]
for i in range(n):
    a[i] = [int(_) for _ in input().strip()]
cnt = [int(_) for _ in input().split()]
party = []
while True:
    piv = -1
    for i in range(n):
        if cnt[i] == 0:
            piv = i
    if piv == -1: break
    party.append(piv + 1)
    for i in range(n):
        if a[piv][i] == 1:
            cnt[i] -= 1
print(len(party))
print(' '.join(map(str, party)))


    
