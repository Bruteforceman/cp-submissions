import math
import sys
input = sys.stdin.readline
t = int(input())

for cs in range(t):
	n, m, x, y = map(int, input().split())
	ans = 0
	for i in range(n):
		s = input().strip()
		cnt = 0
		blocks = []
		for j in s:
			if j == '*':
				blocks.append(cnt)
				cnt = 0
			else:
				cnt = cnt + 1
		blocks.append(cnt)
		for j in blocks:
			ans += (j % 2) * x
			ans += (j // 2) * min(2 * x, y)
	print(ans)