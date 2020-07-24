#include <bits/stdc++.h>
using namespace std;
const int alpha = 20;
int g[26][26];
bool vis[26];
void dfs(int x) {
  vis[x] = true;
  for(int i = 0; i < alpha; i++) {
    if(g[x][i] == 1 && vis[i] == false) {
      dfs(i);
    }
  }
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    bool bad = false;
    memset(g, 0, sizeof g);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) {
      if(a[i] < b[i]) {
        g[a[i] - 'a'][b[i] - 'a'] = 1;
        g[b[i] - 'a'][a[i] - 'a'] = 1;
      } else if (a[i] > b[i]) {
        bad = true;
      }
    }
    int ans = alpha;
    for(int i = 0; i < alpha; i++) {
      if(vis[i] == false) {
        dfs(i);
        ans -= 1;
      }
    }
    if(bad) ans = -1;
    cout << ans << endl;
  }
  return 0;
}
