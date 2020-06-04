#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e6;
const int mod = 1000000000 + 7;
int a[maxn];
int x[maxn], y[maxn];
int dif[maxn];
long long power(int b, int e) {
  long long pw = b;
  long long ans = 1;
  while(e) {
    if(e & 1) ans = (ans * pw) % mod;
    pw = (pw * pw) % mod;
    e >>= 1;
  }
  return ans;
}
void solve() {
  int n, p;
  scanf("%d %d", &n, &p);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n, greater <int> ());
  if(p == 1) {
    printf("%d\n", n % 2);
    return ;
  }
  long long sumA = 0, sumB = 0;
  set <int> P, Q, rel;
  for(int i = 0; i < n; i++) {    
    int e = P.empty() ? -1 : *P.rbegin();
    int f = Q.empty() ? -1 : *Q.rbegin();
    int cur = a[i];
    while(true) {
      if(e < f) {
        if(x[cur] < p - 1) break;
        x[cur++] = 0;
      } else {
        if(y[cur] < p - 1) break;
        y[cur++] = 0;
      }
    }
    if(e < f) {
      sumA += power(p, a[i]);
      sumA %= mod;
      x[cur] += 1;
    }
    else {
      sumB += power(p, a[i]);
      sumB %= mod;
      y[cur] += 1;
    }
    for(int j = a[i]; j <= cur; j++) {
      if(dif[j] < 0) Q.erase(j);
      else if (dif[j] > 0) P.erase(j);
      dif[j] = x[j] - y[j];
      if(dif[j] < 0) Q.insert(j);
      else if (dif[j] > 0) P.insert(j);
      rel.insert(j);
    }
  }
  for(auto i : rel) {
    x[i] = y[i] = dif[i] = 0;
  }
  int e = P.empty() ? -1 : *P.rbegin();
  int f = Q.empty() ? -1 : *Q.rbegin();
  if(e < f) printf("%lld\n", (mod + sumB - sumA) % mod);
  else printf("%lld\n", (mod + sumA - sumB) % mod);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}
