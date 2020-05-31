import math
import sys
input = sys.stdin.readline

t = int(input())
for cs in range(t):
	s = input().strip()
	n = len(s)
	cnt = [0, 0]
	pre = [[0] * n, [0] * n]
	suf = [[0] * n, [0] * n]
	for i in range(n):
		c = ord(s[i]) - ord('0')
		cnt[c] += 1
		pre[0][i], pre[1][i] = cnt[0], cnt[1]

	cnt = [0, 0]
	for i in range(n - 1, -1, -1):
		c = ord(s[i]) - ord('0')
		cnt[c] += 1
		suf[0][i], suf[1][i] = cnt[0], cnt[1]

	ans = min(pre[0][n - 1], pre[1][n - 1])
	for i in range(n - 1):
		ans = min(ans, pre[0][i] + suf[1][i + 1])
		ans = min(ans, pre[1][i] + suf[0][i + 1])
	print(ans)