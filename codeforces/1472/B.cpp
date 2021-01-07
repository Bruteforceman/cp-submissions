#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> a (n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int one = count(a.begin(), a.end(), 1);
    int two = count(a.begin(), a.end(), 2);
    if(one % 2 == 1) {
      cout << "NO" << endl;
    } else if (one == 0 && two % 2 == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
