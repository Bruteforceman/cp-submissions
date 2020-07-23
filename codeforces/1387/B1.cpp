#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector <int> g[maxn];
int a[maxn];
int ans;

bool dfs(int x, int par) {
  bool done = false;
  for(auto i : g[x]) {
    if(i != par) {
      bool var = dfs(i, x);
      if(var == false) {
        done = true;
        swap(a[x], a[i]);
        ans += 2;
      }
    }
  }
  return done;
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  for(int i = 1; i <= n; i++) a[i] = i;
  bool var = dfs(1, 0);
  if(!var) {
    ans += 2;
    swap(a[1], a[g[1].back()]);
  }
  printf("%d\n", ans);
  for(int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
