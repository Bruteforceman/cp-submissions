#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
vector <int> g[maxn];
vector <int> v[maxn];
int par[maxn];
int dep[maxn];
int vis[maxn];

void dfs(int x) {
  v[dep[x]].push_back(x);
  vis[x] = true;
  for(auto i : g[x]) {
    if(i != par[x] && vis[i] == false) {
      par[i] = x;
      dep[i] = 1 + dep[x];
      dfs(i);
    }
  }
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i <= n; i++) {
    g[i].clear();
    v[i].clear();
    vis[i] = false;
  }
  for(int i = 1; i <= m; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  dep[1] = par[1] = 0;
  dfs(1);
  int bound = (n + 1) / 2;
  for(int i = 1; i <= n; i++) {
    if(dep[i] + 1 >= bound) {
      printf("PATH\n");
      printf("%d\n", dep[i] + 1);
      int cur = i;
      while(cur != 0) {
        printf("%d ", cur);
        cur = par[cur];
      }
      printf("\n");
      return ;
    }
  }
  printf("PAIRING\n");
  vector <pair <int, int>> ans;
  for(int i = 0; i <= n; i++) {
    for(int j = 1; j < v[i].size(); j += 2) {
      ans.emplace_back(v[i][j - 1], v[i][j]);
    }
  }
  printf("%d\n", (int) ans.size());
  for(auto i : ans) {
    printf("%d %d\n", i.first, i.second);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}
