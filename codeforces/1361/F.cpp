#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define left lEfT
#define right rIgHt
typedef tree<int,
             null_type,
             less<int>,
             rb_tree_tag,
             tree_order_statistics_node_update> orderset;

const int maxn = 5e5 + 10; 
int p[maxn], w[maxn];
pair <int, int> t[maxn * 4];
int n;

void build(int c = 1, int b = 1, int e = n - 1) {
  if(b == e) {
    t[c] = make_pair(w[b], b);
    return ;
  }
  int m = (b + e) >> 1;
  int l = c << 1; 
  int r = l + 1;
  build(l, b, m);
  build(r, m + 1, e);
  t[c] = min(t[l], t[r]);
}
pair <int, int> query(int x, int y, int c = 1, int b = 1, int e = n - 1) {
  if(x <= b && e <= y) {
    return t[c];
  }
  if(y < b || e < x) return make_pair(INT_MAX, 0);
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  return min(query(x, y, l, b, m), query(x, y, r, m + 1, e));
}

vector <int> g[maxn];
pair <int, int> range[maxn];
int idx;
int left[maxn], right[maxn];

int solve(int l, int r) {
  int c = ++idx;
  range[c] = make_pair(l, r);
  if(r - l == 1) return c;
  int m = query(l + 1, r - 1).second;
  left[c] = solve(l, m);
  right[c] = solve(m, r);
  return c;
}

orderset cont[maxn];
long long dp[maxn];
long long inv[maxn];

void add(int x, int val, int sign, int c = 1) {
  if(range[c].second - range[c].first == 1) return ;
  int l = left[c], r = right[c];
  if(x <= range[l].second) {
    if(sign > 0) cont[l].insert(val);
    else cont[l].erase(val);
    inv[c] += sign * int(cont[r].order_of_key(val));
    add(x, val, sign, l);
  } else {
    if(sign > 0) cont[r].insert(val);
    else cont[r].erase(val);
    inv[c] += sign * int(cont[l].size() - cont[l].order_of_key(val));
    add(x, val, sign, r);
  }
  long long pairs = 1LL * cont[l].size() * cont[r].size(); 
  dp[c] = dp[l] + dp[r] + min(inv[c], pairs - inv[c]);
}
int main() { 
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for(int i = 1; i < n; ++i) scanf("%d", &w[i]);
  build();
  solve(0, n);
  for(int i = 1; i <= n; i++) add(i, p[i], 1);
  int q;
  scanf("%d", &q);
  for(int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x != y) {
      add(x, p[x], -1);
      add(y, p[y], -1);
      swap(p[x], p[y]);
      add(x, p[x], 1);
      add(y, p[y], 1);
    }
    printf("%lld\n", dp[1]);
  }
  return 0;
}
