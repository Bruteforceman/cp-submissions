#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int before[maxn], a[maxn];
int arr[maxn];
int n;

struct node {
  int val, cnt;
  int lazy;
  node() {
    val = INT_MAX;
    cnt = 0;
  }
  void add(int x) {
    val += x;
    lazy += x;
  }
} t[maxn * 4];
void pushdown(int c) {
  int l = c << 1;
  int r = l + 1;
  t[l].add(t[c].lazy);
  t[r].add(t[c].lazy);
  t[c].lazy = 0;
}
void merge(node &cur, node l, node r) {
  cur.val = min(l.val, r.val);
  cur.cnt = 0;
  if(cur.val == l.val) cur.cnt += l.cnt;
  if(cur.val == r.val) cur.cnt += r.cnt;
}

void add(int x, int y, int val, int c = 1, int b = 0, int e = n - 1) {
  if(x > y) return ;
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
void build(int c = 1, int b = 0, int e = n - 1) {
  t[c].val = t[c].lazy = 0;
  t[c].cnt = e - b + 1;
  if(b == e) return ;
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  build(l, b, m);
  build(r, m + 1, e);
}
int main() {
  scanf("%d", &n);
  map <int, int> pos;
  auto addNum = [&] (int x, int val) {
    int cur = x;
    for(int i = 1; i < 3 && cur != -1; i++) {
      cur = before[cur];
    }
    add(cur + 1, x, val);
    if(cur != -1) {
      cur = before[cur];
      add(0, cur, val);
    }
  };
  build();
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);    
    if(pos.find(a[i]) == pos.end()) {
      before[i] = -1;
    } else {
      before[i] = pos[a[i]];
      addNum(before[i], -1);
    }
    addNum(i, 1);
    if(t[1].val == 0) {
      ans += t[1].cnt - (n - i - 1);
    }
    pos[a[i]] = i;
  }
  printf("%lld\n", ans);
}
