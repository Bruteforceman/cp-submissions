#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 1e9;
int n, k;
int a[maxn];
int dp[maxn];
bool good(int g) {
  int ans = 0;
  int opt = 0;
  for(int i = n; i >= 0; i--) {
    dp[i] = -inf;
    if(a[i] <= g) {
      dp[i] = bool(i) + bool(i < n) + opt;
    }
    ans = max(ans, dp[i]);
    if(i < n) opt = max(opt, dp[i + 1]);
  }
  return ans >= k;
}
int main() {
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int l = 0, r = 1000000000;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(good(mid)) r = mid;
    else l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
