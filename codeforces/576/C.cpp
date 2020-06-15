#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int ord[maxn], x[maxn], y[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
    ord[i] = i;
  }
  sort(ord, ord + n, [&] (int i, int j) {
      if(x[i] / 1000 == x[j] / 1000) return (x[i] / 1000) % 2 == 0 ? y[i] < y[j] : y[i] > y[j];
      return x[i] / 1000 < x[j] / 1000;
      } );
  for(int i = 0; i < n; i++) {
    printf("%d ", ord[i] + 1);
  }
  puts("");
}
