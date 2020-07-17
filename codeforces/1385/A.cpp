#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int low = min({x, y, z});
    int high = max({x, y, z});
    vector <int> v ({low, low, high});
    bool good = false;
    do {
      if(x == max(v[0], v[1]) && y == max(v[1], v[2]) && z == max(v[2], v[0])) {
        good = true;
        break;
      }
    } while (next_permutation(v.begin(), v.end()));
    if(good) printf("YES\n%d %d %d\n", v[0], v[1], v[2]);
    else printf("NO\n");
  }
}
