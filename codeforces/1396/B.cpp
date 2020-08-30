#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
int a[maxn];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int sum = 0;
  for(int i = 0; i < n - 1; i++) {
    sum += a[i];
  }
  int total = sum + min(sum + 1, a[n - 1]);
  if(total % 2 == 1) {
    cout << "T" << endl;
  } else {
    cout << "HL" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
