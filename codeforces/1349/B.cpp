#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, k;
int a[maxn];
int p[maxn];

void solve() {
  scanf("%d %d", &n, &k);
  bool found = false;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if(a[i] < k) a[i] = -1;
    else if (a[i] > k) a[i] = 1;
    else {
      found = true;
      a[i] = 1;
    }
  }
  if(!found) {
    printf("no\n");
    return ;
  }
  if(n == 1) {
    printf("yes\n");
    return ;
  }
  set <int> par;
  for(int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i];
    if(par.size() && p[i] > *par.begin()) {
      printf("yes\n");
      return ;
    }
    par.insert(p[i - 1]);
  }
  printf("no\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
  return 0;
}
