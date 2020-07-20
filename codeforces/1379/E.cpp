#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int s[maxn];
void impossible() {
  puts("NO");
  exit(0);
}
vector <int> g[maxn];
int sub[maxn];
int cnt;
void check(int x) {
  sub[x] = 1;
  for(int i : g[x]) {
    check(i);
    sub[x] += sub[i];
  }
  if(g[x].size() == 2) {
    int p = g[x][0], q = g[x][1];
    if(sub[p] >= 2 * sub[q] || sub[q] >= 2 * sub[p]) {
      ++cnt;
    }
  }
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if(n == 1 && k == 0) {
    puts("YES");
    puts("0");
    exit(0);
  }
  if(n % 2 == 0 || n < 2 * k + 3) {
    impossible();
  }
  if(k <= 1) {
    if(__builtin_popcount(n + 1) == 1 && k != 0) {
      impossible();
    }
    if(__builtin_popcount(n + 1) != 1 && k == 0) {
      impossible();
    }
    puts("YES");
    for(int i = 1; i <= n; i++) printf("%d ", i / 2);
    puts("");
    exit(0);
  }
  int rem = n - 2 * (k - 1);
  for(int i = 1; i <= rem; i++) {
    s[i] = i / 2;
  }
  int cur = rem;
  int prev = 1;
  for(int i = 1; i < k; i++) {
    int var = ++cur;
    s[prev] = s[var] = ++cur;
    prev = cur;
  }
  if(__builtin_popcount(rem + 1) == 1) {
    s[rem - 1] = s[rem] = n - 1; 
  }
  int root = 1;
  for(int i = 1; i <= n; i++) {
    if(s[i] > 0) g[s[i]].push_back(i);
    else root = i;
  }
  check(root);
  if(cnt != k) {
    puts("NO");
    exit(0);
  }
  puts("YES");
  for(int i = 1; i <= n; i++) printf("%d ", s[i]);
  puts("");
  return 0;
}
