#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int par[maxn];
int sub[maxn];
int p[maxn];
int vis[maxn];
int root(int x) {
  if(x == par[x]) return par[x];
  return par[x] = root(par[x]);
}
void join(int p, int q) {
  p = root(p);
  q = root(q);
  if(p != q) {
    par[p] = q;
    sub[q] += sub[p];
  }
}
void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    p[x] = i;
  }
  for(int i = 1; i <= n + 1; i++) {
    par[i] = i;
    sub[i] = 1;
  }
  sub[n + 1] = -n - 1;
  bool bad = false;
  auto count = [&] (int x) {
    return sub[root(x)];
  };
  multiset <int> s;
  for(int i = 1; i <= n + 1; i++) {
    s.insert(count(i));
  }
  for(int i = 1; i <= n; i++) {
    int x = p[i];
 //   cout << x << ' ' << opt << ' ' << count(x) << endl; 
    if(count(x) != *s.rbegin()) {
      bad = true;
      break;
    }
    s.erase(s.find(count(x + 1)));
    s.erase(s.find(count(x)));
    join(x, x + 1);
    s.insert(count(x));
  }
  if(bad) puts("No");
  else puts("Yes");
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
