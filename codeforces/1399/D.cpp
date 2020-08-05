#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
char s[maxn];
int ans[maxn];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    set <int> cont[2];
    int idx = 0;
    for(int i = 0; i < n; i++) {
      int c = (s[i] - '0');
      if(cont[c ^ 1].empty()) {
        cont[c ^ 1].insert(++idx);
      }
      ans[i] = *cont[c ^ 1].begin();
      cont[c ^ 1].erase(ans[i]);
      cont[c].insert(ans[i]);
    }
    printf("%d\n", idx);
    for(int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
