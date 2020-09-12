#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector <int> g[maxn];
int sub[maxn];
void subtree(int x, int par) {
  sub[x] = 1;
  for(int i : g[x]) {
    if(i != par) {
      subtree(i, x);
      sub[x] += sub[i];
    }
  }
}
int centroid(int x, int par, int range) {
  for(int i : g[x]) {
    if(i != par && sub[i] > range) {
      return centroid(i, x, range);
    }
  }
  return x;
}
pair <int, int> getLeaf(int x, int par) {
  for(int i : g[x]) {
    if(i != par) {
      return getLeaf(i, x);
    }
  }
  return make_pair(x, par);
}
void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) g[i].clear();
  for(int i = 1; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  subtree(1, 0);
  int root = centroid(1, 0, n / 2);
  subtree(root, 0);
  pair <int, int> any;
  for(int i : g[root]) {
    if(sub[i] * 2 == n) {
      auto j = getLeaf(i, root);
      printf("%d %d\n", j.first, j.second);
      printf("%d %d\n", j.first, root);
      return ;
    }
    any = make_pair(i, root);
  }
  printf("%d %d\n", any.first, any.second);
  printf("%d %d\n", any.first, any.second);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
