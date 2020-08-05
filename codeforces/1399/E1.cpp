#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector <pair <int, int>> g[maxn];
int leaf[maxn];
int par[maxn];
void dfs(int x, int p) {
  leaf[x] = 0;
  int child = 0;
  for(auto i : g[x]) {
    if(i.first != p) {
      par[i.first] = i.second;
      dfs(i.first, x);
      leaf[x] += leaf[i.first];
      child += 1;
    }
  }
  leaf[x] += (child == 0);
}
void solve() {
  int n;
  long long S;
  scanf("%d %lld", &n, &S);
  for(int i = 0; i <= n; i++) g[i].clear();
  for(int i = 1; i < n; i++) {
    int p, q, r;
    scanf("%d %d %d", &p, &q, &r);
    g[p].emplace_back(q, r);
    g[q].emplace_back(p, r);
  }
  dfs(1, 0);
  long long need = -S;
  vector <long long> v;
  for(int i = 2; i <= n; i++) {
    need += 1LL * leaf[i] * par[i];
    int cost = par[i];
    while(cost > 0) {
      v.push_back(1LL * leaf[i] * ((cost + 1) / 2));
      cost /= 2;
    }
  }
  sort(v.begin(), v.end(), greater <long long> ());
  int ans = 0;
  for(auto i : v) {
    if(need > 0) {
      need -= i;
      ans += 1;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
