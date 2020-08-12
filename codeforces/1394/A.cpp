#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int big[maxn], small[maxn];
long long pre[maxn];
int p, q;
int n, m, d;
long long solve(int sz) {
  if(sz <= 0) return 0;
  // (x - 1) * (d + 1) + 1 <= sz
  // (x - 1) * (d + 1) <= sz - 1
  // (x - 1) <= (sz - 1) / (d + 1)
  return pre[(sz - 1) / (d + 1) + 1];
}
int main() {
  scanf("%d %d %d", &n, &d, &m);
  for(int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if(x <= m) small[++p] = x;
    else big[++q] = x;
  }
  sort(big + 1, big + q + 1, greater <int> ());
  sort(small + 1, small + p + 1, greater <int> ());
  for(int i = 1; i <= q; i++) {
    pre[i] = pre[i - 1] + big[i];
  }
  long long ans = 0;
  long long sum = 0;
  for(int i = 0; i <= p; i++) {
    sum += small[i];
    ans = max(ans, solve((p - i) + q) + sum);
  }
  printf("%lld\n", ans);
  return 0;
}
