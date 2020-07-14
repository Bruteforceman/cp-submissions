#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
vector <int> g[maxn];
set <int> v[maxn];
int dp[maxn], in[maxn];
bool del[maxn];
void impossible() {
    cout << -1 << endl;
    exit(0);
}
int dfs(int x) {
    int &ans = dp[x];
    if(ans != -1) return ans;
    ans = max(1, a[x]);
    for(auto i : g[x]) {
        ans = max(ans, 1 + dfs(i));
    }
    if(a[x] && ans != a[x]) impossible();
    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int p, q;
        cin >> p >> q;
        g[p].push_back(q);
        in[q] += 1;
    }
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) if(dfs(i) > k) {
        impossible();
    }

    priority_queue <pair <int, int>> Q;
    for(int i = 1; i <= n; i++) {
        v[dfs(i)].insert(i);
        if(in[i] == 0) {
            int val = a[i] ? -1 : dfs(i);
            Q.emplace(val, i);
        }
    }
    for(int i = k; i >= 1; i--) {
        if(v[i].size() == 0) {
            while(!Q.empty() && del[Q.top().second]) Q.pop();
            if(!Q.empty()) {
                int x = Q.top().second;
                int y = Q.top().first;
                if(y == -1) impossible();
                v[y].erase(x);
                v[i].insert(x);
                a[x] = i;
            } else impossible();
        }
        for(int j : v[i]) {
            del[j] = true;
            for(int x : g[j]) {
                in[x] -= 1;
                if(in[x] == 0) {
                    int val = a[x] ? -1 : dfs(x);
                    Q.emplace(val, x);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        int val = a[i] ? a[i] : dfs(i);
        cout << val << ' ';
    }
    cout << endl;
}
