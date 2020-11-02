#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  int last = a[0];
  a[0] = 0;
  for(int i = 1; i < n; i++) {
    int val = max(a[i - 1], a[i] - last);
    val = min(val, a[i]);
    last = a[i] - val;
    a[i] = val;
  }
  if(is_sorted(a, a + n)) printf("YES\n");
  else printf("NO\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
