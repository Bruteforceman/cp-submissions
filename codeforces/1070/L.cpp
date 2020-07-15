#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int a[maxn][maxn];
int col[maxn];
int deg[maxn];
bool vis[maxn];
int n;

void recurse() { 
  int piv = -1;
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    if(deg[i] % 2 == 1) {
      piv = i;
      break;
    }
  }
  if(piv == -1) {
    for(int i = 1; i <= n; i++) {
      if(vis[i]) continue;
      col[i] = 0;
    }
    return ;
  }
  vis[piv] = true;
  vector <int> adj;
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    if(a[piv][i] == 1) {
      a[piv][i] = a[i][piv] = 0;
      adj.push_back(i);
      deg[i] -= 1;
    }
  }
  for(auto i : adj) {
    for(auto j : adj) {
      if(i == j) continue;
      if(a[i][j] == 1) {
        a[i][j] = 0;
        deg[i] -= 1;
      } else {
        a[i][j] = 1;
        deg[i] += 1;
      }
    }
  }
  recurse();
  int cnt[] = {0, 0};
  for(int i : adj) {
    cnt[col[i]] += 1;
  }
  col[piv] = cnt[0] % 2 == 0 ? 0 : 1;
}
void solve() {
  int m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) a[i][j] = 0;
  memset(deg, 0, sizeof deg);
  memset(vis, false, sizeof vis);
  for(int i = 1; i <= m; i++) {
    int p, q;
    cin >> p >> q;
    a[p][q] = a[q][p] = 1;
    deg[p] += 1;
    deg[q] += 1;
  }
  recurse();
  cout << *max_element(col + 1, col + n + 1) + 1 << endl;
  for(int i = 1; i <= n; i++) cout << 1 + col[i] << ' ';
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
