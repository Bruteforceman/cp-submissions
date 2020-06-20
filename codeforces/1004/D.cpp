#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int cnt[maxn];
int aux[maxn];
void check(int n, int m, int x, int y) {
  if(x < 0 || y < 0) return ;
  if(x >= n || y >= m) return ;
  for(int i = 0; i <= n * m; i++) aux[i] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      aux[abs(x - i) + abs(y - j)] += 1;
    }
  }
  for(int i = 0; i <= n * m; i++) {
    if(aux[i] != cnt[i]) return ;
  }
  printf("%d %d\n", n, m);
  printf("%d %d\n", x + 1, y + 1);
  exit(0);
}
int main() {
  int t;
  scanf("%d", &t);
  int far = 0;
  for(int i = 0; i < t; i++) {
    int x;
    scanf("%d", &x);
    cnt[x] += 1;
    far = max(far, x);
  }
  if(cnt[0] != 1) {
    puts("-1");
    exit(0);
  }
  int expect = 4;
  int piv = 0;
  for(int i = 1; i <= t; i++) {
    if(cnt[i] != expect) {
      piv = i;
      break;
    }
    expect += 4;
  }
  for(int i = 1; i * i <= t; i++) {
    if(t % i != 0) continue;
    int j = t / i;
    check(i, j, i - piv, far - (i - piv));
    check(i, j, far - (j - piv), j - piv);
  }
  puts("-1");
}
