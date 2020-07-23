#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 1e5 + 10;
bool vis[maxn];
double val[maxn];

vector <pair <int, int>> g[maxn];
struct cont {
  long long a, b; // a + bx
  cont (long long a, long long b) : a(a), b(b) {}
  cont () {}
} e[maxn];
struct fraction {
  long long num, den;
  fraction () {}
  fraction (long long num, long long den) : num(num), den(den) {}
}; 

fraction last;
vector <int> node;
void check(cont p, cont q) {
  if(p.b == q.b) {
    if(p.a != q.a) {
      cout << "NO" << endl;
      exit(0);
    }
  } else {
    fraction f = fraction(p.a - q.a, q.b - p.b);
    if(last.num * f.den != f.num * last.den) {
      cout << "NO" << endl;
      exit(0);
    }
    last = f;
  }
}
void dfs(int x) {
  vis[x] = true;
  node.push_back(x);
  for(auto i : g[x]) {
    cont var = cont(i.second - e[x].a, -e[x].b);
    if(vis[i.first] == false) {
      e[i.first] = var;
      dfs(i.first);
    } else {
      check(e[i.first], var);
    }
  }
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int p, q, r;
    cin >> p >> q >> r;
    g[p].emplace_back(q, r);
    g[q].emplace_back(p, r);
  }
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    last = fraction(0, 0);
    node.clear();
    e[i] = cont(0, 1);
    dfs(i);
    double value;
    if(last.den != 0) {
      value = double(last.num) / last.den;
    } else {
      vector <long long> median;
      for(int j : node) {
        long long a = e[j].a, b = e[j].b;
        if(b < 0) {
          a *= -1;
          b *= -1;
        }
        median.push_back(-a);
      }
      sort(median.begin(), median.end());
      value = median[median.size() / 2];
    }
    for(int j : node) {
      val[j] = e[j].a + e[j].b * value;
    }
  }
  cout << "YES" << endl;
  for(int i = 1; i <= n; i++) cout << val[i] << " ";
  cout << endl;
  return 0;
}
