#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn];

struct node {
  long long sum;
  int minVal, lazy;
  node() {
    sum = 0;
    minVal = 0;
    lazy = -1;
  }
  void change(int val, int sz) {
    sum = 1LL * sz * val;
    minVal = val;
    lazy = val;
  }
} t[maxn * 4];
void pushdown(int c, int b, int e) {
  if(t[c].lazy == -1) return ;
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  t[l].change(t[c].lazy, m - b + 1);
  t[r].change(t[c].lazy, e - m);
  t[c].lazy = -1;
}
void merge(node &cur, node l, node r) {
  cur.sum = l.sum + r.sum;
  cur.minVal = r.minVal;
}
void update(int x, int y, int val, int c = 1, int b = 1, int e = n) {
  if(x <= b && e <= y) {
    t[c].change(val, e - b + 1);
    return ;
  }
  if(y < b || e < x) return ;
  pushdown(c, b, e);
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  update(x, y, val, l, b, m);
  update(x, y, val, r, m + 1, e);
  merge(t[c], t[l], t[r]);
}
int query(int val, int c = 1, int b = 1, int e = n) {
  if(b == e) {
    return t[c].minVal <= val ? b : n + 1;
  }
  pushdown(c, b, e);
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(t[l].minVal <= val) {
    return query(val, l, b, m);
  } else {
    return query(val, r, m + 1, e);
  }
}
pair <long long, int> getSum(int x, long long val, int c = 1, int b = 1, int e = n) {
  if(x == b && t[c].sum <= val) return make_pair(t[c].sum, n + 1);
  if(b == e) {
    return make_pair(0, b);
  }
  pushdown(c, b, e);
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(m < x) {
    return getSum(x, val, r, m + 1, e);
  } else {
    auto left = getSum(x, val, l, b, m);
    if(left.second > n) {
      auto right = getSum(m + 1, val - left.first, r, m + 1, e);
      right.first += left.first;
      return right;
    }
    return left;
  }
}
void max_update(int x, int y) {
  int l = query(y);
  if(l <= x) update(l, x, y);
}
int solve(int x, int y) {
  int ans = 0;
  while(x <= n) {
    x = max(x, query(y));
    if(x <= n) {
      auto nxt = getSum(x, y);
      ans += nxt.second - x;
      x = nxt.second;
      y -= nxt.first;
    }
  }
  return ans;
}
int main() {
  int q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    update(i, i, a[i]);
  }
  while(q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    if(t == 1) {
      max_update(x, y);
    } else {
      printf("%d\n", solve(x, y)); 
    }
  }
  return 0;
}
