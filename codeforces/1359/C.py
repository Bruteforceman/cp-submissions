import math
import sys
from fractions import Fraction 
input = sys.stdin.readline
ts = int(input())
 
# (h + c) * n / 2n = (h + c) / 2
# ((h + c) * n + h) / (2n + 1) = (h + c) * n/(2n + 1) + h/(2n + 1)
 
res = []
for cs in range(ts):
	h, c, t = map(int, input().split())
	if 2 * t <= (h + c):
		res.append(2)
	else:
		l, r = 0, int(1e9)
		while l < r:
			mid = (l + r) // 2
			if (h + c) * mid + h <= t * (mid + mid + 1):
				r = mid
			else:
				l = mid + 1
		opt = l
		init = Fraction(h - c)
		ans = 2
		for i in range(opt - 1, opt + 1):
			if i < 0:
				continue
			if Fraction(t) < Fraction((h + c) * i + h, 2*i + 1):
				dist = Fraction((h + c) * i + h, 2*i + 1) - Fraction(t)
			else:
				dist = Fraction(t) - Fraction((h + c) * i + h, 2*i + 1)
			if dist < init:
				init = dist
				ans = 2 * i + 1 
		res.append(ans)
 
print('\n'.join(map(str, res)))