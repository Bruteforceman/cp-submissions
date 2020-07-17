#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
char s[maxn];

int solve(int l, int r, char c) {
  if(l == r) {
    return s[l] != c;
  }
  int m = (l + r) >> 1;
  int x = solve(l, m, c + 1);
  int y = solve(m + 1, r, c + 1);
  int cnt[2] = {0, 0};
  for(int i = l; i <= r; i++) cnt[i > m] += (s[i] != c);
  return min(cnt[0] + y, cnt[1] + x);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    scanf("%s", s);
    printf("%d\n", solve(0, n - 1, 'a'));
  }
  return 0;
}
