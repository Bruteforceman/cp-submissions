#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int a[maxn];

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool good = false;
    for(int i = 1; i < n; i++) {
      if(a[i - 1] <= a[i]) good = true;
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
