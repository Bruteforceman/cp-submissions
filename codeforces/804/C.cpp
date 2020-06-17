#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
vector <int> g[maxn], v[maxn];
int col[maxn];
void dfs(int x, int par) {
  set <int> taken;
  for(int i : v[x]) {
    if(col[i] != 0) {
      taken.insert(col[i]);
    }
  }
  int cur = 1;
  for(int i : v[x]) {
    if(col[i] == 0) {
      while(taken.count(cur)) ++cur;
      col[i] = cur;
      taken.insert(cur);
    }
  }
  for(int i : g[x]) {
    if(i != par) {
      dfs(i, x);
    }
  }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    int s; scanf("%d", &s);
    while(s--) { int x; scanf("%d", &x); v[i].push_back(x); }
  }
  for(int i = 1; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  int root = 1;
  for(int i = 1; i <= n; i++) {
    if(v[i].size() > v[root].size()) root = i;
  }
  dfs(root, 0);
  printf("%d\n", max(1, (int) v[root].size()));
  for(int i = 1; i <= m; i++) {
    printf("%d ", max(1, col[i]));  
  }
  puts("");
  return 0;
}
