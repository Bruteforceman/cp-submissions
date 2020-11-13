#include <bits/stdc++.h>
using namespace std;
int a[100010];

int main() {
  int n;
  cin >> n;
  int tot = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    tot ^= a[i];
  }
  if(n % 2 == 0 && tot != 0) {
    cout << "NO" << endl;
    exit(0);
  }
  cout << "YES" << endl;
  if(n & 1) {
    cout << (n / 2) * 2 << endl;
    for(int i = 2; i <= n; i += 2) {
      cout << 1 << " " << i << " " << i + 1 << endl;
    }
    for(int i = n; i > 1; i -= 2) {
      cout << 1 << " " << i - 1 << " " << i << endl;
    }
  } else {
    cout << n - 2 << endl;
    for(int i = 2; i < n; i += 2) {
      cout << 1 << " " << i << " " << i + 1 << endl;
      cout << i << " " << i + 1 << " " << n << endl;
    }
  }
  return 0;
}
