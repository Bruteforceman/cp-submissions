#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int cnt[maxn * 4];
long long sum[maxn * 4];
int val[maxn];
int idx;

void update(int x, int v, int c = 1, int b = 1, int e = idx) {
  if(b == e) {
    cnt[c] += v;
    sum[c] += v * val[b];
    return ;
  }
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(x <= m) update(x, v, l, b, m);
  else update(x, v, r, m + 1, e);
  cnt[c] = cnt[l] + cnt[r];
  sum[c] = sum[l] + sum[r];
}
long long get(int x, int c = 1, int b = 1, int e = idx) {
  if(b == e) {
    return sum[c] * x;
  }
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(x <= cnt[r]) {
    return get(x, r, m + 1, e);
  } else {
    return get(x - cnt[r], l, b, m) + sum[r];
  }
}

int tp[maxn], d[maxn];

int main() {
  int n;
  scanf("%d", &n);
  map <int, int> cmp;
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &tp[i], &d[i]);
    cmp[abs(d[i])];
  }
  for(auto &i : cmp) {
    i.second = ++idx;
    val[idx] = i.first;
  }
  set <int> s;
  long long total = 0;
  for(int i = 1; i <= n; i++) { 
    if(not s.empty()) {
      int top = *s.begin();
      update(cmp[top], 1);
    }
    if(d[i] < 0) {
      update(cmp[abs(d[i])], -1);
      if(tp[i] == 1) {
        s.erase(abs(d[i]));
      }
    } else {
      update(cmp[abs(d[i])], 1);
      if(tp[i] == 1) {
        s.insert(abs(d[i]));
      }
    }
    if(not s.empty()) {
      int top = *s.begin();
      update(cmp[top], -1);
    }
    total += d[i];
    printf("%lld\n", total + get(s.size()));
  }
  return 0;
}
