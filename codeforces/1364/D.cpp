#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int par[maxn], dep[maxn];
vector <int> g[maxn];
vector <pair <int, int>> extra;
void dfs(int x, int p) {
  for(auto i : g[x]) {
    if(i == p) continue;
    if(par[i] == -1) {
      dep[i] = 1 + dep[x];
      par[i] = x;
      dfs(i, x);
    } else if (dep[i] < dep[x]) {
      extra.emplace_back(x, i);
    }
  }
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= m; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  memset(par, -1, sizeof par);
  par[1] = dep[1] = 0;
  dfs(1, 0);

  if (extra.empty()) {
    int c = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += ((dep[i] % 2) == 0);
    if(2 * cnt <= n) c ^= 1; 
    printf("1\n");
    cnt = ((k + 1) / 2);
    for(int i = 1; i <= n; i++) {
      if(cnt <= 0) break;
      if(dep[i] % 2 == c) {
        printf("%d ", i);
        --cnt;
      }
    }
    printf("\n");
  } else {
    int opt = n;
    auto edge = extra[0];
    for(auto i : extra) {
      if(opt > dep[i.first] - dep[i.second]) {
        opt = dep[i.first] - dep[i.second];
        edge = i;
      }
    }
    vector <int> cycle;
    int now = edge.first;
    while(true) {
      cycle.push_back(now);
      if(now == edge.second) break;
      now = par[now];
    }
    if(cycle.size() <= k) {
      printf("2\n%d\n", (int)cycle.size());
      for(auto i : cycle) printf("%d ", i);
      printf("\n");
    } else {
      printf("1\n");
      int cnt = ((k + 1) / 2);
      for(int i = 0; i < cycle.size(); i += 2) {
        if(cnt <= 0) break;
        --cnt;
        printf("%d ", cycle[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
