#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef pair <int, int> pii;
vector <pii> start[maxn], fin[maxn];
struct {
  int s, m, r;
} a[maxn];
bool vis[maxn];
long long sum[maxn], ans[maxn];
int idx;
long long prop[maxn * 4], add[maxn * 4];
void updateProg(int x, int y, int val, int c = 1, int b = 1, int e = idx) {
  if(x > y) return ;
  if(x <= b && e <= y) {
    prop[c] += val;
    return ;
  }
  if(y < b || e < x) return ;
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  updateProg(x, y, val, l, b, m);
  updateProg(x, y, val, r, m + 1, e);
}
void updateVal(int x, int y, int val, int c = 1, int b = 1, int e = idx) {
  if(x > y) return ;
  if(x <= b && e <= y) {
    add[c] += val;
    return ;
  }
  if(y < b || e < x) return ;
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  updateVal(x, y, val, l, b, m);
  updateVal(x, y, val, r, m + 1, e);
}
long long query(int x, int c = 1, int b = 1, int e = idx) {
  if(x >= idx) x = idx;
  if(b == e) {
    return prop[c] * x + add[c];
  }
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(x <= m) return query(x, l, b, m) + prop[c] * x + add[c];
  else return query(x, r, m + 1, e) + prop[c] * x + add[c];
}
int par[maxn];
int root(int x) {
  if(x == par[x]) return x;
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
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d %d", &a[i].s, &a[i].m, &a[i].r);
    idx = max(idx, a[i].m);
  }
  idx += 1;
  int q;
  scanf("%d", &q);
  map <int, int> id;
  for(int i = 1; i <= n + 1; i++) {
    par[i] = i;
  }
  for(int i = 1; i <= q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    start[l].emplace_back(t, i);
    fin[r].emplace_back(t, i);
    while(root(l) <= r) {
      l = root(l);
      ans[i] += min(1LL * a[l].m, a[l].s + 1LL * a[l].r * t);
      join(l, l + 1);
    }
    id[t] = i;
  }
  set <int> cont;
  for(int i = 1; i <= n; i++) {
    for(auto j : start[i]) {
      cont.insert(j.first);
      auto it = cont.find(j.first);
      int before = -1, after = -1;
      if(it != cont.begin()) {
        before = *prev(it); 
        ans[j.second] -= query(j.first - before);
      }
      if(next(it) != cont.end()) {
        after = *next(it);
        ans[id[after]] -= query(after - j.first);
      }
      if(before != -1 && after != -1) {
        ans[id[after]] += query(after - before);
      }
    }
    if(a[i].r > 0) {
      updateProg(1, a[i].m / a[i].r, a[i].r);
      updateVal((a[i].m / a[i].r) + 1, idx, a[i].m);
    }
    for(auto j : fin[i]) {
      auto it = cont.find(j.first);
      int before = -1, after = -1;
      if(it != cont.begin()) {
        before = *prev(it); 
        ans[j.second] += query(j.first - before);
      }
      if(next(it) != cont.end()) {
        after = *next(it);
        ans[id[after]] += query(after - j.first);
      }
      if(before != -1 && after != -1) {
        ans[id[after]] -= query(after - before);
      }
      cont.erase(j.first);
    }
  }
  for(int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0; 
}
