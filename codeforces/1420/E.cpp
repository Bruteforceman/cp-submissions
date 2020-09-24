#include <bits/stdc++.h>
using namespace std;
const int maxn = 82;
const int inf = 1e8;
vector <int> pos;
int mem[maxn][maxn][maxn * (maxn - 1) / 2];
int aux[maxn][maxn];
int n;

inline int choose(int x) {
  return (x * (x - 1)) / 2;
}
int dp(int cur, int one, int rem) {
  if(rem < 0) return inf;
  if(one == pos.size()) return choose(n - cur); 
  int &ans = mem[cur][one][rem];
  if(ans != -1) return ans;
  ans = inf;
  for(int i = cur; i < n; i++) {
    int moves = abs(pos[one] - i);
    ans = min(ans, dp(i + 1, one + 1, rem - moves) + choose(i - cur));
  }
  return ans;
}
int optimal(int cur, int one) {
  if(one == pos.size()) return choose(n - cur);
  int &ans = aux[cur][one];
  if(ans != -1) return ans;
  ans = inf;
  for(int i = cur; i < n; i++) {
    ans = min(ans, optimal(i + 1, one + 1) + choose(i - cur));
  }
  return ans;
}

int getOpt() {
  int cur = 0, one = 0;
  int moves = 0;
  while(one < pos.size()) {
    for(int i = cur; i < n; i++) {
      if(optimal(cur, one) == optimal(i + 1, one + 1) + choose(i - cur)) {
        moves += abs(pos[one] - i);
        cur = i + 1;
        one += 1;
        break;
      }
    }
  }
  return moves;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x == 1) pos.push_back(i);
  }
  memset(mem, -1, sizeof mem);
  memset(aux, -1, sizeof aux);
  int total = choose(n - pos.size());
  int need = getOpt();
  for(int i = 0; i <= choose(n); i++) {
    cout << total - dp(0, 0, min(need, i)) << " ";
  }
  cout << endl;
  return 0;
}
