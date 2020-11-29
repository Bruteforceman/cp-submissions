#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], dp[maxn];
char s[maxn];

void solve() {
  int n, p, k;
  scanf("%d %d %d", &n, &p, &k);
  scanf("%s", s);
  for(int i = 1; i <= n; i++) {
    a[i] = (s[i - 1] - '0');
  }
  int x, y;
  scanf("%d %d", &x, &y);
  for(int i = n; i >= 1; i--) {
    dp[i] = (a[i] == 0);
    if(i + k <= n) dp[i] += dp[i + k];
  }
  long long ans = LLONG_MAX;
  for(int i = n - p + 1; i >= 1; i--) {
    ans = min(ans, 1LL * (i - 1) * y + 1LL * dp[i + p - 1] * x);
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
  return 0;
}
