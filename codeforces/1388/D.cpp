#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
vector <int> g[maxn];
vector <int> order;
long long ans;
long long sub[maxn];
  
void dfs(int x) {
  sub[x] = a[x];
  for(int i : g[x]) {
    dfs(i);
    sub[x] += max(0LL, sub[i]);
  }
  ans += sub[x];
  return ;
}
void getOrder(int x) {
  for(int i : g[x]) {
    if(sub[i] > 0) {
      getOrder(i);
    }
  }
  order.push_back(x);
  for(int i : g[x]) {
    if(sub[i] <= 0) {
      getOrder(i);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if(b[i] != -1) {
      g[b[i]].push_back(i);
    }
  }
  for(int i = 1; i <= n; i++) {
    if(b[i] == -1) {
      dfs(i);
      getOrder(i);
    }
  }
  printf("%lld\n", ans);
  for(auto i : order) printf("%d ", i);
  printf("\n");
  return 0;
}
