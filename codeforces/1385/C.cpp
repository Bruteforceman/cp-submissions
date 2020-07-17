#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int now = n;
    while(now > 1 && a[now] <= a[now - 1]) {
      now -= 1;
    }
    while(now > 1 && a[now] >= a[now - 1]) {
      now -= 1;
    }
    printf("%d\n", now - 1);
  }
  return 0;
}
