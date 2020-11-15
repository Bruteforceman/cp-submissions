#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int dp[maxn][maxn];

int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  s = "$" + s;
  t = "$" + t;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(s[i] == t[j]) {
        dp[i][j] = 2 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(0, max(dp[i - 1][j], dp[i][j - 1]) - 1);
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
