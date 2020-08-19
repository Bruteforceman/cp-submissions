#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for(int i = n - 1; i > 0; i--) {
      if(a[i - 1] > a[i]) {
        ans += a[i - 1] - a[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
