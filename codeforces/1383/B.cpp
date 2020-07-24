#include <bits/stdc++.h>
using namespace std;
const int bit = 32;
int mem[111][111][2];
int dp(int x, int y, int par) {
  if(y == 0) return par == 0;
  if(mem[x][y][par] != -1) return mem[x][y][par];
  int ans = 0;
  if(x > 0) {
    if(dp(x - 1, y, (y & 1) ^ par ^ 1) == 0) {
      ans = 1;
    }
  }
  if(dp(x, y - 1, ((y - 1) & 1) ^ par) == 0) {
    ans = 1;
  }
  return mem[x][y][par] = ans; 
}
int win(int x, int y) {
  if(x % 2 == 1) return 1;
  if(y % 4 == 1) return 1;
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int cnt[bit];
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      for(int j = 0; j < bit; j++) {
        cnt[j] += (x >> j) & 1;
      }
    }
    int ans = -1;
    for(int i = bit - 1; i >= 0; i--) {
      if(cnt[i] % 2 == 1) {
        ans = win(n - cnt[i], cnt[i]);
        break;
      }
    }
    if(ans == 1) printf("WIN\n");
    else if (ans == 0) printf("LOSE\n");
    else printf("DRAW\n");
  }
  return 0;
}
