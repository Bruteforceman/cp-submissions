#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10010];
int d[1005][10005];
const long long inf = 1e18;
struct node {
  int t, x, dist;
  node () {}
  node (int t, int x, int dist) : t(t), x(x), dist(dist) {}
  bool operator < (node p) const {
    return dist > p.dist;
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + m);
  int g, r;
  scanf("%d %d", &g, &r);
  memset(d, -1, sizeof d);
  deque <node> Q;
  Q.emplace_back(0, 0, 0);
  d[0][0] = 0;
  long long ans = inf;
  while(!Q.empty()) {
    node p = Q.front();
    Q.pop_front();
    if(a[p.x] == n) {
      ans = min(ans, 1LL * p.dist * (r + g) + p.t);  
    }
    if(p.x < m - 1) {
      int rem = a[p.x + 1] - a[p.x];
      if(p.t + rem <= g && d[p.t + rem][p.x + 1] == -1) {
        d[p.t + rem][p.x + 1] = p.dist;
        Q.emplace_front(p.t + rem, p.x + 1, p.dist);
      }
    }
    if(p.x > 0) {
      int rem = a[p.x] - a[p.x - 1];
      if(p.t + rem <= g && d[p.t + rem][p.x - 1] == -1) {
        d[p.t + rem][p.x - 1] = p.dist;
        Q.emplace_front(p.t + rem, p.x - 1, p.dist);
      }
    }
    if(p.t == g && d[0][p.x] == -1) {
      d[0][p.x] = 1 + p.dist;
      Q.emplace_back(0, p.x, 1 + p.dist);
    }
  }
  if(ans == inf) ans = -1;
  printf("%lld\n", ans);
  return 0;
}