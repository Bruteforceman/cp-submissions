#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector <int> g[300010];
int col[300010];
int cnt[2];
bool bad;
long long P[300010];
const int mod = 998244353;

void dfs(int x) {
    cnt[col[x]] += 1;
    for(auto i : g[x]) {
        if(col[i] == -1) {
            col[i] = 1 ^ col[x];
            dfs(i);
        } else if (col[i] == col[x]) {
            bad = true;
        }
    }
}

int main() {
    //ios_base :: sync_with_stdio (false);
    //cin.tie(0);
    int t;
    scanf("%d", &t);

    P[0] = 1;
    for(int i = 1; i <= 300000; i++) {
        P[i] = P[i-1] << 1;
        P[i] %= mod;
    }
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) {
            col[i] = -1;
            g[i].clear();
        }
        for(int i = 1; i <= m; i++) {
            int p, q;
            scanf("%d %d", &p, &q);
            g[p].push_back(q);
            g[q].push_back(p);
        }
        bad = false;
        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            if(col[i] == -1) {
                cnt[0] = cnt[1] = 0;
                col[i] = 0;
                dfs(i);
                ans *= (P[cnt[0]] + P[cnt[1]]);
                ans %= mod;
            }
        }
        if(bad) {
            printf("0\n");
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}
