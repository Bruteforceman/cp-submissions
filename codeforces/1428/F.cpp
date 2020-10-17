#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n;
struct node {
  long long sum;
  int max;
  int prop;
  void add(int x, int sz) {
    sum += 1LL * x * sz;
    max += x;
    prop += x;
  }
} t[maxn * 4];

void pushdown(int c, int b, int e) {
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  t[l].add(t[c].prop, m - b + 1);
  t[r].add(t[c].prop, e - m);
  t[c].prop = 0;
}
void merge(node &cur, node l, node r) {
  cur.sum = l.sum + r.sum;
  cur.max = max(l.max, r.max);
}
void update(int x, int y, int val, int c = 1, int b = 0, int e = n - 1) {
  if(x <= b && e <= y) {
    t[c].add(val, e - b + 1);
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
int query(int val, int c = 1, int b = 0, int e = n - 1) {
  if(b == e) {
    return t[c].max >= val ? b : b - 1;
  }
  pushdown(c, b, e);
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(t[r].max >= val) {
    return query(val, r, m + 1, e);
  } else {
    return query(val, l, b, m);
  }
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);

  cin >> n;
  string s;
  cin >> s;
  int last = -1;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '0') {
      last = i;
    } else {
      int seg = i - last;
      int id = query(seg);
      if(id < i) update(id + 1, i, 1);
    }
    ans += t[1].sum;
  }
  cout << ans << endl;
  return 0;
}
