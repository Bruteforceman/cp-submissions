#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int par[maxn], sub[maxn], col[maxn];
vector <pair <int, int>> parHis, colHis, subHis;
bool bad[maxn];
int c[maxn];

int root(int x) {
  while(x != par[x]) {
    x = par[x];
  }
  return x;
}
int getCol(int x) {
  int res = 0;
  while(x != par[x]) {
    res ^= col[x];
    x = par[x];
  }
  return res;
}
void save(int x, int y) {
  parHis.emplace_back(x, par[x]);
  subHis.emplace_back(y, sub[y]);
  colHis.emplace_back(x, col[x]);
}
void join(int x, int y, bool rollback = false) {
  int rx = root(x);
  int ry = root(y);
  int dif = (getCol(x) == getCol(y));
  if(sub[rx] > sub[ry]) swap(rx, ry);
  if(rollback) save(rx, ry);
  par[rx] = ry;
  sub[ry] += sub[rx];
  col[rx] = dif;
}
bool check(int p, int q) {
  if(root(p) == root(q) && getCol(p) == getCol(q)) return false;
  return true;
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  map <pair <int, int>, vector <pair <int, int>>> cont;
  for(int i = 1; i <= m; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    if(c[p] > c[q]) swap(p, q);
    cont[make_pair(c[p], c[q])].emplace_back(p, q);
  }
  for(int i = 1; i <= n; i++) {
    par[i] = i;
    col[i] = 0;
    sub[i] = 1;
  }
  int active = k;
  for(int i = 1; i <= k; i++) {
    auto v = cont[make_pair(i, i)];
    for(auto j : v) {
      int p = j.first;
      int q = j.second;
      if(check(p, q)) {
        join(p, q);
      } else {
        bad[i] = true;
        active -= 1;
        break;
      }
    }
  }
  long long ans = (1LL * active * (active - 1)) / 2; 
  for(auto i : cont) {
    if(i.first.first == i.first.second) continue;
    if(bad[i.first.first] || bad[i.first.second]) continue;
    auto v = i.second;
    for(auto j : v) {
      int p = j.first;
      int q = j.second;
      if(check(p, q)) {
        join(p, q, true);
      } else {
        ans -= 1;
        break;
      }
    }
    while(not parHis.empty()) {
      auto ph = parHis.back();
      auto ch = colHis.back();
      auto sh = subHis.back();
      parHis.pop_back();
      colHis.pop_back();
      subHis.pop_back();
      par[ph.first] = ph.second;
      col[ch.first] = ch.second;
      sub[sh.first] = sh.second;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
