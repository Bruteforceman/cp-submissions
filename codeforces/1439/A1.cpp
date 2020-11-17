#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
#define endl '\n'

int a[maxn][maxn];
vector <pair <int, int>> A, B, C;

void solve(int x, int y) {
  vector <pair <int, int>> v;
  v.emplace_back(x, y);
  v.emplace_back(x + 1, y);
  v.emplace_back(x, y + 1);
  v.emplace_back(x + 1, y + 1);
  int cnt = 0;
  for(auto i : v) cnt += a[i.first][i.second];
  int bit = (cnt & 1) ^ 1;
  for(auto i : v) {
    if(a[i.first][i.second] == bit) {
      vector <pair <int, int>> aux;
      for(auto j : v) {
        if(j != i) aux.push_back(j);
      }
      A.push_back(aux[0]);
      B.push_back(aux[1]);
      C.push_back(aux[2]);
    }
    a[i.first][i.second] = 0;
  }
}
void solve() {
  A.clear();
  B.clear();
  C.clear();
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for(int j = 1; j <= m; j++) {
      a[i][j] = s[j - 1] - '0';
    }
  }
  for(int i = 1; i <= n; i += 2) {
    for(int j = 1; j <= m; j += 2) {
      int x = i;
      int y = j;
      if(x == n) x -= 1;
      if(y == m) y -= 1;
      solve(x, y);
    }
  }
  cout << A.size() << endl;
  for(int i = 0; i < A.size(); i++) {
    cout << A[i].first << " " << A[i].second << " " << B[i].first << " " << B[i].second << " " << 
      C[i].first << " " << C[i].second << endl;
  }
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
