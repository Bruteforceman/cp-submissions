#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn];
int n;

void solve(int l, int r) {
  int len = r - l + 1;
  int inv = 0;
  for(int i = 0; i < n; i++) {
    if((1LL * i * len) % n == 1) {
      inv = i;
      break;
    }
  }
  printf("%d %d\n", l, r);
  for(int i = l; i <= r; i++) {
    long long right = (n - (a[i] % n)) % n;
    right = (right * inv) % n;
    printf("%lld ", right * len);
    a[i] += right * len;
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  if(n > 1) {
    solve(1, 1);
    solve(2, n);
  } else {
    printf("1 1\n0\n1 1\n0\n1 1\n%lld\n", -a[1]);
    exit(0);
  }
  printf("%d %d\n", 1, n);
  for(int i = 1; i <= n; i++) {
    printf("%lld ", -a[i]);
  }
  printf("\n");
}
