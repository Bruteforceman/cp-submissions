#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int dp[maxn], suf[maxn];
int t[maxn], x[maxn], y[maxn];

int main() {
  int r, n;
  scanf("%d %d", &r, &n);
  for(int i = 1; i <= n; i++) scanf("%d %d %d", &t[i], &x[i], &y[i]);
  t[0] = 0;
  x[0] = y[0] = 1;
  suf[n + 1] = 0;
  for(int i = n; i >= 0; i--) {
    int val = (i > 0);
    dp[i] = val;
    for(int j = i + 1; j <= n; j++) {
      if(t[j] - t[i] >= 2 * r) {
        dp[i] = max(dp[i], val + suf[j]);
        break;
      }
      if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i]) {
        dp[i] = max(dp[i], val + dp[j]);
      }
    }
    suf[i] = max(dp[i], suf[i + 1]); 
  }
  printf("%d\n", dp[0]);
  return 0;
}
