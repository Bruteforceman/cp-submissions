#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int x, y, k;
    cin >> x >> y >> k;
    long long need = 1LL * k * (1 + y) - 1;
    x -= 1;
    cout << (need + x - 1) / x + k << endl;
  }
  return 0;
}
