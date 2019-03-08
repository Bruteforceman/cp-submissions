#include "bits/stdc++.h"
using namespace std;
typedef pair <int, int> pii;

vector <int> g[120010];
vector <int> t[120010];
pii st[52 * 120010];
int now;

bool vis[52][120010];
int scc[52][120010];
int cnt[52 * 120010];
vector <pii> lis[52 * 120010];
bool open[52][120010];
int n, m, day;
int dp[52 * 120010];
bool mark[120010];

inline void dfs(int x, int d) {
	int nxt = (d + 1) % day;
	for(auto i : g[x]) {
		if(!vis[nxt][i]) {
			vis[nxt][i] = true;
			dfs(i, nxt);
		}
	}
	st[now++] = pii(x, d);
}
inline void rev(int x, int d, int id) {
	scc[d][x] = id;
	lis[id].emplace_back(x, d);
	int nxt = (d - 1 + day) % day;
	for(auto i : t[x]) {
		if(scc[nxt][i] == -1) {
			rev(i, nxt, id);
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &n, &m, &day);
	for(int i = 1; i <= m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].emplace_back(q);
		t[q].emplace_back(p);
	}
	for(int i = 1; i <= n; i++) {
		char s[51];
		scanf("%s", s);
		for(int d = 0; d < day; d++) {
			open[d][i] = (s[d] == '1');
 		}
	}
	memset(vis, false, sizeof vis);
	for(int i = 1; i <= n; i++) {
		for(int d = 0; d < day; d++) {
			if(!vis[d][i]) {
				dfs(i, d);
			}
		}
	}
	memset(scc, -1, sizeof scc);
	int id = 0;
	for(int i = now - 1; i >= 0; i--) {
		int x = st[i].first;
		int d = st[i].second;
		if(scc[d][x] == -1) {
			rev(x, d, ++id);
			for(auto j : lis[id]) {
				if(!mark[j.first] && open[j.second][j.first]) {
					++cnt[id];
					mark[j.first] = true;
				}
			}
			for(auto j : lis[id]) {
				mark[j.first] = false;
			}
		} 
	}
	for(auto i = id; i >= 1; i--) {
		dp[i] = cnt[i];
		for(auto j : lis[i]) {
			for(auto x : g[j.first]) {
				int y = scc[(j.second + 1) % day][x];
				if(y != i) {
					dp[i] = max(dp[i], dp[y] + cnt[i]);
				}
				assert(y >= i);
			}
		}
	}
	printf("%d\n", dp[scc[0][1]]);
	return 0;
}