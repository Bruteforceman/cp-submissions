#include <bits/stdc++.h>
using namespace std;
int a[111];
int main() {
  int t;
  scanf("%d", &t);
  for(int cs = 1; cs <= t; cs++) {
    int n, m;
    scanf("%d %d", &n, &m);
    set <int> s;
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
      s.insert(a[i]);
    }
    if(s.size() > m) {
      puts("-1");
      continue;
    }
    vector <int> v (s.begin(), s.end());
    while(v.size() < m) v.push_back(1);
    printf("%d\n", n * m);
    for(int i = 0; i < n; i++) {
      for(int j : v) printf("%d ", j);
    }
    printf("\n");
  }
  return 0;
}
    
