#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long inf = 1e18;
long long a[maxn];
long long r1, r2, r3, d;
int n;
long long mem[2][2][maxn];

long long way(long long x, int num) {
  if(num == 0) return (x + 2) * r1;
  else if (num == 1) return r1 + r2;
  else return x * r1 + r3;
}
long long dp(int cur, int need, int suff) {
  if(cur == n) {
    return need ? inf : 0;
  }
  long long &ans = mem[need][suff][cur];
  if(ans != -1) return ans;
  ans = inf;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j <= 3; j++) {
      for(int k = 0; k < 2; k++) {
        if(need && j == 0) continue;
        if(suff && k == 0) continue;
        if(!k && j % 2 == 1) continue;
        if(k && j % 2 == 0) continue;
        int cnt = j;
        int newNeed = (i < 2 && cnt < 2);
        ans = min(ans, d * cnt + way(a[cur], i) + dp(cur + 1, newNeed, k));
      }
    }
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  scanf("%lld %lld %lld %lld", &r1, &r2, &r3, &d);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
  memset(mem, -1, sizeof mem);
  printf("%lld\n", d * (n - 1) + dp(0, 0, 0));
  return 0;
}
