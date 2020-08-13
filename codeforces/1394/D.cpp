#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector <int> g[maxn];
int h[maxn], t[maxn];
long long up[maxn], down[maxn];

void dfs(int x, int par) {
  for(int i : g[x]) {
    if(i != par) {
      dfs(i, x);
    }
  }
  vector <long long> v;
  long long sum = 0;
  int in = 0, out = 0;
  int extra = (par != 0); 
  for(int i : g[x]) {
    if(i != par) {
      if(h[i] > h[x]) {
        ++out;
        sum += down[i];
      }
      else if (h[i] < h[x]) {
        ++in;
        sum += up[i];
      }
      else {
        ++out;
        sum += down[i];
        v.push_back(up[i] - down[i]);
      }
    }
  }
  sort(v.begin(), v.end());
  up[x] = 1LL * t[x] * max(in, out + extra) + sum;
  down[x] = 1LL * t[x] * max(in + extra, out) + sum;
  for(auto i : v) {
    sum += i;
    out -= 1;
    in += 1;
    up[x] = min(up[x], 1LL * t[x] * max(in, out + extra) + sum);
    down[x] = min(down[x], 1LL * t[x] * max(in + extra, out) + sum);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for(int i = 1; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  dfs(1, 0);
  printf("%lld\n", up[1]);
  return 0;
}
