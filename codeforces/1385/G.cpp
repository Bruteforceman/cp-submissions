#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
vector <pair <int, int>> g[maxn];
bool vis[maxn];

void dfs(int x, vector <int> &cycle) {
  for(auto i : g[x]) {
    if(vis[abs(i.second)] == false) {
      vis[abs(i.second)] = true;
      cycle.push_back(i.second);
      dfs(i.first, cycle);
    }
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
  map <int, int> cnt;
  for(int i = 1; i <= n; i++) {
    cnt[a[i]] += 1;
    cnt[b[i]] += 1;
  }
  for(int i = 1; i <= n; i++) {
    if(cnt[i] != 2) {
      printf("-1\n");
      return ;
    }
  }
  for(int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
  }
  for(int i = 1; i <= n; i++) {
    g[a[i]].emplace_back(b[i], i);
    g[b[i]].emplace_back(a[i], -i);
  }
  vector <int> sols;
  for(int i = 1; i <= n; i++) {
    vector <int> v;
    dfs(i, v);
    int cnt = 0;
    for(int i : v) cnt += (i < 0);
    if(cnt * 2 > v.size()) for(int &i : v) i *= -1;
    for(int i : v) {
      if(i < 0) sols.push_back(-i);
    }
  }
  printf("%d\n", (int) sols.size());
  for(int i : sols) printf("%d ", i);
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
  return 0;
}
