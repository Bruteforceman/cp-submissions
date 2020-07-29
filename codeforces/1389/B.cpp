#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e16;
int n, k, z;
int a[maxn];
long long mem[2][6][maxn];

long long dp(int last, int left, int right) {
  int pos = 1 - left + right;
  if(pos < 1 || pos > n || left > z) return -inf;
  if(left + right == k) return a[pos];
  long long &ans = mem[last][left][right];
  if(ans != -1) return ans;
  ans = -inf;
  if(last != 0) {
    ans = max(ans, a[pos] + dp(0, left + 1, right));
  }
  ans = max(ans, a[pos] + dp(1, left, right + 1));
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &n, &k, &z);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j <= z; j++) {
        for(int x = 0; x <= k; x++) {
          mem[i][j][x] = -1;
        }
      }
    }
    printf("%lld\n", dp(1, 0, 0));
  }
}
