#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 998244353;
vector <int> start[maxn * 2], fin[maxn * 2];
long long fac[maxn], inv[maxn];
int l[maxn], r[maxn];

long long modpow(long long b, long long e) {
  long long ans = 1;
  long long exp = b;
  while(e) {
    if(e & 1) ans = (ans * exp) % mod;
    exp = (exp * exp) % mod;
    e >>= 1;
  }
  return ans;
}
long long nCr(int n, int r) {
  if(n < r) return 0;
  long long num = fac[n];
  long long den = (inv[r] * inv[n - r]) % mod;
  return (num * den) % mod;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  map <int, int> cmp;
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    cmp[l[i]] = cmp[r[i]] = 0;
  }
  int idx = 0;
  for(auto &i : cmp) {
    i.second = ++idx;
  }
  for(int i = 1; i <= n; i++) {
    l[i] = cmp[l[i]];
    r[i] = cmp[r[i]];
    start[l[i]].push_back(i);
    fin[r[i]].push_back(i);
  }
  fac[0] = inv[0] = 1;
  for(int i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = modpow(fac[i], mod - 2);
  }
  long long ans = 0;
  set <int> cont;
  for(int i = 1; i <= idx; i++) {
    for(int j : start[i]) {
      ans += nCr(cont.size(), k - 1);
      ans %= mod;
      cont.insert(j);
    }
    for(int j : fin[i]) {
      cont.erase(j);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
