#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn * 2];
vector <pair <int, int>> g[1 << 20];
bool done[maxn * 2];
int n;
vector <int> st;

void dfs(int x) {
  while(!g[x].empty()) {
    auto j = g[x].back();
    g[x].pop_back();
    int e = (j.second + 1) / 2;
    if(done[e]) continue;
    done[e] = true;
    dfs(j.first);
    st.push_back(4 * e - 1 - j.second);
    st.push_back(j.second);
  }
}
void solve(int f) {
  for(int i = 0; i < (1 << 20); i++) g[i].clear();
  for(int i = 1; i <= n; i++) {
    int p = a[2 * i - 1] & ((1 << f) - 1);
    int q = a[2 * i] & ((1 << f) - 1);
    g[p].emplace_back(q, 2 * i - 1);
    g[q].emplace_back(p, 2 * i);
    done[i] = false;
  }
  for(int i = 0; i < (1 << 20); i++) {
    if(g[i].size() % 2 == 1) return ;
  }
  st.clear();
  for(int i = 0; i < (1 << 20); i++) {
    if(g[i].size() > 0) {
      dfs(i);
      break;
    }
  }
  if(st.size() == 2 * n) {
    printf("%d\n", f);
    for(int i : st) printf("%d ", i);
    printf("\n");
    exit(0);
  }
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d %d", &a[2 * i - 1], &a[2 * i]);
  for(int i = 20; i >= 0; i--) {
    solve(i);
  }
  return 0;
}
