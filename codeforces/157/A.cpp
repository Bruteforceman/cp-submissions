#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> row (n), col (n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int x;
      cin >> x;
      row[i] += x;
      col[j] += x;
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(col[j] > row[i]) ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
