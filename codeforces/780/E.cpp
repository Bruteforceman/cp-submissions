#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector <int> g[maxn];
vector <int> order;
bool vis[maxn];

void dfs(int x) {
  vis[x] = true;
  order.push_back(x);
  for(auto i : g[x]) {
    if(vis[i] == false) {
      dfs(i);
      order.push_back(x);
    }
  }
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  vector <int> current;
  int maxSize = (2 * n + k - 1) / k;
  int cnt = 0;
  for(auto i : order) {
    current.push_back(i);
    if(current.size() == maxSize) {
      printf("%d", (int) current.size());
      cnt = cnt + 1;
      for(auto j : current) printf(" %d", j);  
      printf("\n");
      current.clear();
    }
  }
  if(current.size() == 0) current.push_back(1);
  while(cnt < k) {
    cnt = cnt + 1;
    printf("%d", (int) current.size());
    for(auto j : current) printf(" %d", j);
    printf("\n");
  }
  return 0;
}
