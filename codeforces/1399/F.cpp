#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int l[maxn], r[maxn];
int dp[maxn * 2][maxn * 2];
bitset <maxn * 2> exist[maxn * 2];
vector <int> g[maxn * 2];
void solve() {
  int n;
  cin >> n;
  map <int, int> cmp;
  for(int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    cmp[l[i]]; cmp[r[i]];
  }
  int idx = 0;
  for(auto &i : cmp) i.second = ++idx;
  for(int i = 0; i <= idx; i++) {
    for(int j = 0; j <= idx; j++) {
      exist[i][j] = dp[i][j] = 0;
    }
    g[i].clear();
  }
  for(int i = 1; i <= n; i++) {
    l[i] = cmp[l[i]];
    r[i] = cmp[r[i]];
    exist[l[i]][r[i]] = 1;
    g[l[i]].push_back(r[i]);
  }
  for(int len = 1; len <= idx; len++) {
    for(int i = 1; i <= idx - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = exist[i][j] + dp[i + 1][j];
      for(int k : g[i]) {
        if(k < j) {
          dp[i][j] = max(dp[i][j], exist[i][j] + dp[i][k] + dp[k + 1][j]);
        }
      }
    }
  }
  cout << dp[1][idx] << endl;
}
  
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
