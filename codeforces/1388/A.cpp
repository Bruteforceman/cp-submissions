#include <bits/stdc++.h>
using namespace std;
bool good(int x) {
  int factor = 0;
  for(int i = 2; i <= x; i++) {
    int cnt = 0;
    while(x % i == 0) {
      x /= i;
      ++cnt;
    }
    if(cnt > 1) return false;
    else if (cnt) ++factor;
  }
  return factor == 2;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if(n <= 50) {
      for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
          for(int k = j + 1; k <= n; k++) {
            if(good(i) && good(j) && good(k)) {
              int rem = n - i - j - k;
              if(rem > 0 && rem != i && rem != j && rem != k) {
                cout << "YES" << endl;
                cout << i << " " << j << " " << k << " " << rem << endl;
                goto out;
              }
            } 
          }
        }
      }
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << "6 10 14 " << n - 6 - 10 - 14 << endl;
    }
    out:
    {}
  } 
  return 0;
}
