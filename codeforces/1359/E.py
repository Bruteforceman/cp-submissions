import math
import sys
input = sys.stdin.readline
mod = 998244353
n, k = map(int, input().split())
fac = [0] * (n + 1)
inv = [0] * (n + 1)
inv[0] = fac[0] = 1
for i in range(1, n + 1):
	fac[i] = (fac[i - 1] * i) % mod
	inv[i] = pow(fac[i], mod - 2, mod)
def nCr(n, r):
	if n < 0 or n < r:
		return 0
	return (fac[n] * inv[r] * inv[n - r]) % mod
ans = 0
for i in range(1, n + 1):
	ans += nCr((n // i) - 1, k - 1)
	ans %= mod
print(ans)
