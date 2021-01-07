#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> a(n), deg(n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {  
      cin >> a[i];
      sum += a[i];
    }
    for(int i = 1; i < n; i++) {
      int p, q;
      cin >> p >> q;
      p -= 1; q -= 1;
      deg[p] += 1;
      deg[q] += 1;
    }
    vector <int> v;
    for(int i = 0; i < n; i++) {
      deg[i] -= 1;
      while(deg[i]--) v.push_back(a[i]);
    }
    sort(v.begin(), v.end(), greater <int> ());
    for(int i = 0; i < n - 1; i++) {
      cout << sum << " ";
      if(i < v.size()) sum += v[i];
    }
    cout << endl;
  }
  return 0;
}
