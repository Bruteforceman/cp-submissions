#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn], d[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  queue <int> Q;
  for(int i = 1; i <= n; i++) { 
    d[i] = -1;
    if(i == 1 || i == n) {
      d[i] = 0;
    } else if (a[i - 1] == a[i] || a[i] == a[i + 1]) {
      d[i] = 0;
    }
    if(d[i] == 0) Q.push(i);
  }
  int ans = 0;
  while(!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for(int i : {x - 1, x + 1}) {
      if(d[i] == -1) {
        d[i] = d[x] + 1;
        a[i] = a[x];
        Q.push(i);
      }
    }
    ans = max(ans, d[x]);
  }
  printf("%d\n", ans);
  for(int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
