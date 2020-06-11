#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const long long inf = 1e16;
const int mod = 1000000000 + 7;
int l[maxn], r[maxn], w[maxn];
long long dp[maxn][maxn];
int n, m, q;

vector <long long> M, C;
bool bad(int i, int j, int k) {
  // (i, k) <= (i, j)
  return (C[i] - C[k]) * (M[j] - M[i]) <= (C[i] - C[j]) * (M[k] - M[i]); 
}
void addLine(long long m, long long c) {
  M.push_back(m);
  C.push_back(c);
  while(M.size() > 2 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
    M.erase(M.end() - 2);
    C.erase(C.end() - 2);
  }
}
int pt;
long long eval(int x) {
  while(pt + 1 < M.size() && M[pt] * x + C[pt] <= 
      M[pt + 1] * x + C[pt + 1]) {
    ++pt; 
  }
  return M[pt] * x + C[pt];
}
long long sum(long long l, long long r, int id) {
  if(l > r) return 0;
  long long constant = (1LL * C[id] * (r - l + 1)) % mod;
  long long total = (r * (r + 1)) / 2 - (l * (l - 1)) / 2;
  total %= mod;
  return (total * M[id] + constant) % mod; 
}
int main() {
  cin >> n >> m >> q;
  for(int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i] >> w[i];
  }
  dp[0][1] = 0;
  for(int j = 2; j <= n; j++) dp[0][j] = -inf;
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      dp[i][j] = -inf;
    }
    for(int j = 1; j <= m; j++) {
      for(int d = 0; d <= 1; d++) {
        int u = l[j];
        int v = r[j];
        if(d) swap(u, v);
        dp[i][u] = max(dp[i][u], dp[i - 1][v] + w[j]);
      }
    }
  }
  long long ans = 0;
  for(int i = 1; i <= m; i++) {
    long long opt = -inf;
    for(int j = 1; j <= n; j++) {
      opt = max(opt, dp[i][j]);
    }
    ans += opt;
    ans %= mod;
  }
  map <int, vector <int>> cont;
  for(int i = 1; i <= m; i++) {
    cont[w[i]].push_back(i); 
  }
  for(auto &i : cont) {
    long long opt = -inf;
    for(auto j : i.second) {
      opt = max(opt, dp[m][l[j]]);
      opt = max(opt, dp[m][r[j]]);
    }
    addLine(i.first, opt);
  }
  q -= m;
  vector <int> change;
  change.push_back(0);
  for(int i = 0; i + 1 < M.size(); i++) {
    int l = 0, r = q;
    while(l < r) {
      int mid = (l + r + 1) >> 1;
      if(M[i] * mid + C[i] >= M[i + 1] * mid + C[i + 1]) {
        l = mid;   
      } else {
        r = mid - 1;
      }
    }    
    change.push_back(l);
  }
  change.push_back(q);
  for(int i = 0; i < M.size(); i++) {
    ans += sum(change[i] + 1, change[i + 1], i);
    ans %= mod;
  }
  if(ans < 0) ans += mod;
  cout << ans % mod << endl;
  return 0;
}
