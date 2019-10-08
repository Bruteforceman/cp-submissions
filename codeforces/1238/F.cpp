#include "bits/stdc++.h"
using namespace std;
vector <int> g[300010];
int dp[300010];
int ans;

void dfs(int x, int par) {
	int deg = 0;
	int opt1 = 0, opt2 = 0;
	for(auto i : g[x]) {
		if(i == par) continue;
		dfs(i, x);
		if(opt1 < dp[i]) {
			opt2 = opt1;
			opt1 = dp[i];
		} else if (opt2 < dp[i]) {
			opt2 = dp[i];
		}
		++deg;
	}
	dp[x] = max(1, deg + opt1);
	ans = max(ans, opt1 + opt2 + deg - 1 + (par != 0));
	ans = max(ans, dp[x] + (par != 0));
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for(int i = 1; i < n; i++) {
			int p, q;
			scanf("%d %d", &p, &q);
			g[p].push_back(q);
			g[q].push_back(p);
		}
		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}