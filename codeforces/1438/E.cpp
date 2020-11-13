#include <bits/stdc++.h>
using namespace std;
#define prev lol
#define next pol
const int maxn = 2e5 + 10;
const int maxbit = 29;
int a[maxn];
long long pre[maxn];
vector <int> v[maxbit + 1];

int msb(int x) {
  for(int i = maxbit; i >= 0; i--) {
    if((x >> i) & 1) return i;
  }
  return -1;
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    v[msb(a[i])].push_back(i);
    pre[i] = pre[i - 1] + a[i];
  }
  set <pair <int, int>> s;
  auto check = [&] (int i, int j) {
    if(j - i >= 2 && (a[i] ^ a[j]) == (pre[j - 1] - pre[i])) {
      s.insert(make_pair(i, j));
    }
  };
  for(int i = 0; i <= maxbit; i++) {
    for(int j = 1; j < v[i].size(); j++) {
      check(v[i][j - 1], v[i][j]);
    }
    for(int j = 0; j < v[i].size(); j++) {
      int prev, next;
      int x = v[i][j];
      if(j >= 2) {
        prev = v[i][j - 2] + 1;
      } else {
        prev = 1; 
      }
      if(j + 2 < v[i].size()) {
        next = v[i][j + 2];
      } else {
        next = n;
      }
      for(int k = prev; k <= x; k++) {
        check(k, x);
      }
      for(int k = x; k <= next; k++) {
        check(x, k);
      }
    }
  }
  printf("%d\n", (int) s.size());
  return 0;
}
