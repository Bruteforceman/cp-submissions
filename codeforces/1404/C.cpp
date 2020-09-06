#include <bits/stdc++.h> 
using namespace std;
const int maxn = 3e5 + 10; 
const int inf = 1e9; 
int a[maxn]; 
int del[maxn], pre[maxn]; 
int n;

struct node {
  int maxVal, lazy, index;
  void add(int val) {
    maxVal += val;
    lazy += val;
  }
} t[maxn * 4];
void merge(node &t, node l, node r) {
  t.maxVal = max(l.maxVal, r.maxVal);
  if(t.maxVal == r.maxVal) t.index = r.index;
  else t.index = l.index;
}
void pushdown(int c) {
  int l = c << 1;
  int r = l + 1;
  t[l].add(t[c].lazy);
  t[r].add(t[c].lazy);
  t[c].lazy = 0;
}
void build(int c = 1, int b = 1, int e = n) {
  t[c].lazy = 0;
  if(b == e) {
    t[c].maxVal = a[b] - b;
    t[c].index = b;
    return ;
  }
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  build(l, b, m);
  build(r, m + 1, e);
  merge(t[c], t[l], t[r]);
}
void add(int x, int y, int val, int c = 1, int b = 1, int e = n) {
  if(x <= b && e <= y) {
    t[c].add(val);
    return ;
  }
  if(y < b || e < x) return ;
  pushdown(c);
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  add(x, y, val, l, b, m);
  add(x, y, val, r, m + 1, e);
  merge(t[c], t[l], t[r]);
}
int getLast() {
  while(t[1].maxVal > 0) {
    add(t[1].index, t[1].index, -inf);
  }
  if(t[1].maxVal == 0) {
    return t[1].index;
  } else {
    return -1;
  }
}

vector <int> g[maxn * 4];
void buildM(int c = 1, int b = 1, int e = n) {
  if(b == e) {
    g[c].push_back(del[b]);
    return ;
  }
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  buildM(l, b, m);
  buildM(r, m + 1, e);
  merge(g[l].begin(), g[l].end(), g[r].begin(), g[r].end(), back_inserter(g[c]));
}
int query(int x, int y, int val, int c = 1, int b = 1, int e = n) {
  if(x <= b && e <= y) {
    return lower_bound(g[c].begin(), g[c].end(), val) - g[c].begin();
  }
  if(y < b || e < x) return 0;
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  return query(x, y, val, l, b, m) + query(x, y, val, r, m + 1, e);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    del[i] = inf;
  }
  build();


  int cur = 0;
  while(true) {
    int i = getLast();
    if(i == -1) break;
    add(i, n, 1);
    add(i, i, -inf);
    del[i] = ++cur;
  }
  pre[0] = inf;
  for(int i = 1; i <= n; i++) {
    pre[i] = min(pre[i - 1], del[i]);
  }
  buildM();
  while(q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int cnt = query(x + 1, n - y, pre[x]);
    printf("%d\n", cnt);
  }
  return 0;
}
