#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> a (n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum < 0) {
      sort(a.begin(), a.end());
    } else if (sum > 0) {
      sort(a.begin(), a.end(), greater <int> ());
    } else {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for(int i : a) cout << i << " ";
    cout << endl;
  }
  return 0;
}
