import math
import sys
input = sys.stdin.readline

t = int(input())
for cs in range(t):
	n, x = map(int, input().split())
	a = [int(_) for _ in input().split()]
	odd = 0
	for i in a:
		if i % 2 == 1:
			odd = odd + 1
	if odd == 0 or (odd == n and x % 2 == 0) or (x == n and sum(a) % 2 == 0):
		print('No')
	else:
		print('Yes')