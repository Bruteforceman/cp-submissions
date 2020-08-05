#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector <tuple <int, int, int>> g[maxn];
int leaf[maxn];
int par[maxn];
int t[maxn];

void dfs(int x, int p) {
  leaf[x] = 0;
  int child = 0;
  for(auto i : g[x]) {
    int y, cost, type;
    tie(y, cost, type) = i;
    if(y != p) {
      par[y] = cost;
      t[y] = type;
      dfs(y, x);
      leaf[x] += leaf[y];
      child += 1;
    }
  }
  leaf[x] += (child == 0);
}
void solve(int test, int cs) {
  int n;
  long long S;
  scanf("%d %lld", &n, &S);
  vector <tuple <int, int, int, int>> gg;
  for(int i = 0; i <= n; i++) g[i].clear();
  for(int i = 1; i < n; i++) {
    int p, q, r, c;
    scanf("%d %d %d %d", &p, &q, &r, &c);
    g[p].emplace_back(q, r, c);
    g[q].emplace_back(p, r, c);
    gg.emplace_back(p, q, r, c);
  }
  dfs(1, 0);
  long long need = -S;
  vector <pair <long long, pair <int, int>>> v;
  for(int i = 2; i <= n; i++) {
    need += 1LL * leaf[i] * par[i];
    int cost = par[i];
    int iter = 1;
    int sign = t[i] == 1 ? -1 : 1;
    while(cost > 0) {
      long long var = 1LL * leaf[i] * ((cost + 1) / 2) * (3 - t[i]);
      for(int j = 1; j <= t[i]; j++) {
        v.emplace_back(var, make_pair(sign * iter, i));
      }
      cost /= 2;
      iter += 1;
    }
  }
  need *= 2;
  sort(v.begin(), v.end(), greater <pair <long long, pair <int, int>>> ());
  int ans = 0;
  int last = -1;
  for(int i = 0; i < v.size(); i++) {
    if(need > 0) {
      need -= v[i].first;
      last = i;
    }
  }
  if(0 <= last && last + 1 < v.size() && v[last] == 
      v[last + 1]) {
    ans = last + 2;
    need += v[last].first;
    for(int i = last + 2; i < v.size(); i++) {
      if(t[v[i].second.second] == 1 && need <= v[i].first) {
          ans = last + 1;
          break;
      }
    }
    need -= v[last].first;
    need -= v[last + 1].first;
    for(int i = 0; i < last; i++) {
      if(t[v[i].second.second] == 1 && v[i].first + need <= 0) {
        ans = last + 1;
        break;
      }
    }
  } else {
    ans = last + 1;
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  for(int cs = 1; cs <= t; cs++) {
    solve(t, cs);
  }
  return 0;
}
