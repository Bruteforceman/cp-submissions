#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
long long fac[maxn], inv[maxn];
long long suf[maxn];
int d[maxn];
int n;

long long modpow(long long x, int y) {
  long long cur = x;
  long long ans = 1;
  while(y) {
    if(y & 1) ans = (ans * cur) % mod;
    cur = (cur * cur) % mod;
    y >>= 1;
  }
  return ans;
}

long long nPr(int n, int r) {
  long long num = fac[n];
  long long den = inv[n - r];
  return (num * den) % mod;
}
long long getProb(int a, int big, int small) {
  if(a > big) return 0;
  long long ways = (fac[big] * (big - a + 1)) % mod;
  ways = (ways * nPr(n, small)) % mod;
  return (ways * inv[n]) % mod;
}
int main() {
  int m;
  scanf("%d %d", &n, &m);
  fac[0] = inv[0] = 1;
  for(int i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = modpow(fac[i], mod - 2);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  sort(d, d + n);
  for(int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + d[i];
    suf[i] %= mod;
  }
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int id = lower_bound(d, d + n, b) - d;
    long long ans = 0;
    ans += suf[id] * getProb(a, n - id - 1, id);
    ans += (suf[0] - suf[id]) * getProb(a, n - id, id - 1);
    ans %= mod;
    if(ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
}
