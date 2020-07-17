#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector <int> g[maxn];
bool vis[maxn];
int order[maxn];
int cur;
void dfs(int x) {
  vis[x] = true;
  for(auto i : g[x]) {
    if(vis[i] == false) {
      dfs(i);
    }
  }
  order[x] = ++cur;
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <int> c (m), l (m), r (m);
    for(int i = 0; i <= n; i++) {
      vis[i] = false;
      g[i].clear();
    }
    for(int i = 0; i < m; i++) {
      scanf("%d %d %d", &c[i], &l[i], &r[i]);
      if(c[i] == 1) {
        g[l[i]].push_back(r[i]);
      }
    }
    cur = 0;
    for(int i = 1; i <= n; i++) {
      if(vis[i] == false) dfs(i);
    }
    bool good = true;
    for(int i = 0; i < m; i++) {
      if(c[i] && order[l[i]] <= order[r[i]]) {
        good = false;
      }
    }
    if(good) {
      printf("YES\n");
      for(int i = 0; i < m; i++) {
        if(order[l[i]] <= order[r[i]]) swap(l[i], r[i]);
        printf("%d %d\n", l[i], r[i]);
      }
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
