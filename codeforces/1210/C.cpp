#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
vector <int> g[maxn];
vector <pair <long long, int>> can[maxn];
long long a[maxn];
void dfs(int x, int par, int dep) {
    if(par >= 0) {
        auto v = can[par];
        for(auto &i : v) i.first = __gcd(i.first, a[x]);
        v.emplace_back(a[x], dep);
        for(int i = 0; i < v.size(); i++) {
            if(i > 0 && v[i - 1].first == v[i].first) continue;
            can[x].push_back(v[i]);
        }
        can[x].emplace_back(0, dep + 1);
    }
    for(auto i : g[x]) if(i != par) dfs(i, x, dep + 1);
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int p, q;
        cin >> p >> q;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    dfs(1, 0, 0);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < can[i].size(); j++) {
            ans += 1LL * can[i][j - 1].first * (can[i][j].second - can[i][j - 1].second);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
