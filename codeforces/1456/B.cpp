#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int logn = 30;
int a[maxn], b[maxn], pre[maxn];
int msb(int x) {
  for(int i = logn; i >= 0; i--) {
    if((x >> i) & 1) return i;
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = msb(a[i]);
    pre[i] = pre[i - 1] ^ a[i];
  }
  for(int i = 3; i <= n; i++) {
    if(b[i - 2] == b[i - 1] && b[i - 1] == b[i]) {
      printf("1\n");
      exit(0);
    }
  }
  int ans = INT_MAX;
  for(int i = 2; i <= n; i++) {
    for(int j = i - 1; j >= 1; j--) {
      for(int k = i; k <= n; k++) {
        int l = pre[i - 1] ^ pre[j - 1];
        int r = pre[k] ^ pre[i - 1];
        if(l > r) {
          ans = min(ans, (i - 1 - j) + (k - i));
        }
      }
    }
  }
  if(ans > n) ans = -1;
  printf("%d\n", ans);
  return 0;
}
