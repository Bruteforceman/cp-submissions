#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct edge {
  int l, r, cost;
  edge (int l, int r, int cost) : l(l), r(r), cost(cost) {}
  edge () {}
  bool operator < (edge e) const {
    return cost > e.cost;
  }
};
int par[maxn * 2];
int a[maxn], b[maxn];

int root(int x) {
  if(par[x] == x) return x;
  return par[x] = root(par[x]);
}
void join(int x, int y) {
  x = root(x);
  y = root(y);
  if(x != y) {
    par[x] = y;
  }
}
int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  vector <edge> v;
  for(int i = 0; i < m; i++) scanf("%d", &a[i]);
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);
  for(int i = 0; i < m; i++) {
    int s;
    scanf("%d", &s);
    while(s--) {
      int x;
      scanf("%d", &x);
      x -= 1;
      v.emplace_back(x, i + n, a[i] + b[x]);
    }
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  iota(par, par + n + m, 0);
  for(auto e : v) {
    if(root(e.l) != root(e.r)) {
      join(e.l, e.r);
    } else {
      ans += e.cost;
    }
  }
  printf("%lld\n", ans);
}
