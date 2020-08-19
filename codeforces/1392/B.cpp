#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

// a[max] - a[min] - (a[max] - a[i]) = a[i] - a[min]
// a[max] - a[min] - (a[i] - a[min]) = a[max] - a[i]

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    long long k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int minVal = *min_element(a, a + n);
    int maxVal = *max_element(a, a + n);
    if(k & 1) {
      for(int i = 0; i < n; i++) a[i] = maxVal - a[i];
    } else {
      for(int i = 0; i < n; i++) a[i] = a[i] - minVal;
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
