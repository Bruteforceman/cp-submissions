def modpow(b, e, mod):
    ret = 1
    pw = b
    while e > 0:
        if e % 2 == 1: ret = (ret * pw) % mod
        e = e >> 1
        pw = (pw * pw) % mod
    return ret

n, k = map(int, input().split())
mod = 998244353
inv = [0 for _ in range(n + 1)]
fac = [0 for _ in range(n + 1)]
fac[0] = inv[0] = 1

for i in range(n):
    fac[i + 1] = (fac[i] * (i + 1)) % mod
    inv[i + 1] = modpow(fac[i + 1], mod - 2, mod)

def nCr(n, r):
    num = fac[n]
    den = (inv[r] * inv[n - r]) % mod
    return (num * den) % mod


row = n - k
if row < 0 or row > n: 
    print('0')
else:
    ans = 0
    for i in range(row):
        add = (nCr(row, i) * modpow(row - i, n, mod)) % mod
        if i % 2 == 0: ans = ans + add
        else: ans = ans - add

    ans = mod + (ans % mod)
    mult = 2
    if row == n: mult = 1
    print((mult * nCr(n, row) * ans) % mod)

