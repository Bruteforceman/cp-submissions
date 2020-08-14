#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
long long dp[maxn][maxn][maxn];
int x[maxn], y[maxn], z[maxn];
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  for(int i = 1; i <= r; i++) cin >> x[i];
  for(int i = 1; i <= g; i++) cin >> y[i];
  for(int i = 1; i <= b; i++) cin >> z[i];
  sort(x + 1, x + r + 1);
  sort(y + 1, y + g + 1);
  sort(z + 1, z + b + 1);
  long long ans = 0;
  for(int i = 0; i <= r; i++) {
    for(int j = 0; j <= g; j++) {
      for(int k = 0; k <= b; k++) {
        dp[i][j][k] = 0;
        if(i && j) {
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + x[i] * y[j]);
        }
        if(j && k) {
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + y[j] * z[k]);
        }
        if(i && k) {
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + x[i] * z[k]);
        }
        ans = max(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
