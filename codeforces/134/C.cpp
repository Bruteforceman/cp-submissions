#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
pair <int, int> a[maxn];

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1, greater <pair <int, int>> ());
  vector <pair <int, int>> edge;
  for(int i = 1; i <= n; i++) {
    int deg = a[i].first;
    int cur = i + 1;
    int rem = deg;
    if(deg < 0 || i + deg > n) {
      puts("No");
      exit(0);
    }
    while(a[cur].first > a[i + deg].first) {
      a[cur].first -= 1;
      edge.emplace_back(a[i].second, a[cur].second);
      ++cur;
      --rem;
    }
    int l = i + 1, r = n;
    int value = a[i + deg].first;
    while(l < r) {
      int mid = (l + r) >> 1;
      if(a[mid].first < value) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if(a[l].first == value) ++l;
    for(int j = 1; j <= rem; j++) {
      a[l - j].first -= 1;
      edge.emplace_back(a[i].second, a[l - j].second);
    }
  }
  puts("Yes");
  printf("%d\n", (int) edge.size());
  for(auto i : edge) printf("%d %d\n", i.first, i.second);
  return 0;
}
