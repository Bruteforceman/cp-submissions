#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn];
long long diff[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  long long sum = 0;
  long long first = a[1];
  for(int i = 2; i <= n; i++) {
    diff[i] = a[i] - a[i - 1];
    sum += max(0LL, diff[i]);
  }
  auto update = [&] (int l, int r, int x) {
    if(l == 1) {
      first += x;
    } else {
      sum -= max(0LL, diff[l]);
      diff[l] += x;
      sum += max(0LL, diff[l]);
    }
    if(r < n) {
      sum -= max(0LL, diff[r + 1]);
      diff[r + 1] -= x;
      sum += max(0LL, diff[r + 1]);
    }
  };
  auto query = [&] () {
    long long opt = (first - sum) / 2;
    return max(opt + sum, first - opt);
  };
  printf("%lld\n", query());
  int q;
  scanf("%d", &q);
  while(q--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    update(l, r, x);
    printf("%lld\n", query());
  } 
  return 0;
}
