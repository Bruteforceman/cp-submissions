#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int col[maxn];
vector <int> v[maxn];
int par[maxn];
int cnt[2][maxn];
int pref[maxn];
int sum;

int root(int p) {
  if(par[p] == p) return p;
  return par[p] = root(par[p]);
}
int opt(int p) {
  p = root(p);
  if(pref[p] == -1) return min(cnt[0][p], cnt[1][p]);
  else return cnt[pref[p]][p];
}
void join(int x, int y, int diff) {
  int p = root(x);
  int q = root(y);
  if(p != q) {
    sum -= opt(p);
    sum -= opt(q);
    if(v[p].size() > v[q].size()) swap(p, q);
    int inv = col[x] ^ col[y] ^ diff;
    for(int i : v[p]) {
      col[i] ^= inv;
      v[q].push_back(i);
      cnt[col[i]][q] += 1;
    }
    if(pref[p] != -1) pref[q] = pref[p] ^ inv;
    par[p] = q;
    sum += opt(q);
  }
}
void assign(int x, int val) {
  int y = root(x);
  sum -= opt(y);
  pref[y] = col[x] ^ val ^ 1;
  sum += opt(y);
}

int a[maxn];
char s[maxn];
vector <int> can[maxn];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  for(int i = 1; i <= n; i++) a[i] = s[i] - '0';
  for(int i = 1; i <= m; i++) {
    int c;
    scanf("%d", &c);
    while(c--) {
      int x;
      scanf("%d", &x);
      can[x].push_back(i);
    }
  }
  for(int i = 1; i <= m; i++) {
    par[i] = i;
    cnt[0][i] = 1;
    pref[i] = -1;
    col[i] = 0;
    v[i].push_back(i);
  }
  
  for(int i = 1; i <= n; i++) {
    if (can[i].size() == 1) assign(can[i][0], a[i] ^ 1);
    else if (can[i].size() == 2) {
      int p = can[i][0], q = can[i][1];
      join(p, q, a[i] ^ 1);
    }
    printf("%d\n", sum);
  }
  return 0;
}
