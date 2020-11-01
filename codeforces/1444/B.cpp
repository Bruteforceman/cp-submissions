#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 998244353;
long long fac[maxn];
int a[maxn];

long long modpow(long long e, long long x) {
  long long pw = e;
  long long res = 1;
  while(x) {
    if(x & 1) res = (res * pw) % mod;
    pw = (pw * pw) % mod;
    x >>= 1;
  }
  return res;
}


int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n + n; i++) scanf("%d", &a[i]);
  sort(a, a + n + n);
  
  fac[0] = 1;
  for(int i = 1; i <= n + n; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  long long nCr = fac[n + n];
  nCr *= (modpow(fac[n], mod - 2) * modpow(fac[n], mod - 2)) % mod;
  nCr %= mod;

  long long sum = 0;
  for(int i = 0; i < n + n; i++) {
    if(i < n) sum -= a[i];
    else sum += a[i];
  }
  sum %= mod;
  printf("%lld\n", (nCr * sum) % mod);
  return 0;
}
