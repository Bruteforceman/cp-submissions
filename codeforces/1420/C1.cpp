#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const long long inf = 1e17;
long long low[maxn * 4][2], high[maxn * 4][2];
int a[maxn];
int n;

void merge(int c) {
  int l = c << 1;
  int r = l + 1;
  for(int i = 0; i < 2; i++) {
    low[c][i] = inf;
    high[c][i] = -inf; 
  }
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      long long opt = (i == 0) ? high[l][i] + high[r][j] : high[l][i] - low[r][j];
      high[c][(i + j) & 1] = max(high[c][(i + j) & 1], opt);
      opt = (i == 0) ? low[l][i] + low[r][j] : low[l][i] - high[r][j];
      low[c][(i + j) & 1] = min(low[c][(i + j) & 1], opt);
    }
  }
}
void update(int x, int val, int c = 1, int b = 1, int e = n) {
  if(b == e) {
    low[c][0] = high[c][0] = 0;
    low[c][1] = high[c][1] = val;
    return ;
  }
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(x <= m) update(x, val, l, b, m);
  else update(x, val, r, m + 1, e);
  merge(c);
}

int main() {
  int ts;
  scanf("%d", &ts);
  while(ts--) {
    int q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i <= 4 * n; i++) {
      high[i][0] = high[i][1] = 0;
      low[i][0] = low[i][1] = 0;
    }
    for(int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      update(i, a[i]);
    }
    printf("%lld\n", max(high[1][0], high[1][1]));
    for(int i = 1; i <= q; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      swap(a[l], a[r]);
      update(l, a[l]);
      update(r, a[r]);
      printf("%lld\n", max(high[1][0], high[1][1]));
    }
  }
  return 0;
}
