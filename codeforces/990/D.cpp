#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int x[maxn][maxn];

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if(a > 1 && b > 1) {
    cout << "NO" << endl;
    exit(0);
  }
  if(a == 1 && b == 1 && (n == 2 || n == 3)) {
    cout << "NO" << endl;
    exit(0);
  }
  bool inv = (a == 1);
  if(b == 1) swap(a, b);
  for(int i = b + 1; i <= n; i++) {
    x[i - 1][i] = x[i][i - 1] = 1;
  }
  cout << "YES" << endl;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i != j) x[i][j] ^= inv;
      cout << x[i][j];
    }
    cout << endl;
  }
  return 0;
}
