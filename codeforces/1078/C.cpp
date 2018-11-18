#include "bits/stdc++.h"
using namespace std;
int n;
vector <int> g[300010];
vector <int> child;
const int mod = 998244353;
long long fn[2][300010];
long long ans[300010];
long long mem[2][300010];

long long dp(int cur, int take) {
	if(take < 0) return 0;
	if(cur == child.size()) {
		return (take == 0);
	}
	if(mem[take][cur] != -1) return mem[take][cur];
	long long res = 0;
	int c = child[cur];
	res += ans[c] * dp(cur + 1, take);
	res %= mod;
	res += fn[1][c] * dp(cur + 1, take);
	res %= mod;
	res += fn[0][c] * dp(cur + 1, take - 1);
	res %= mod;
	return mem[take][cur] = res;
}

void dfs(int x, int par) {
	for(auto i : g[x]) {
		if(i - par) {
			dfs(i, x);
		}
	}
	child.clear();
	for(auto i : g[x]) {
		if(i - par) {
			child.push_back(i);
		}
	}
	if(child.empty()) {
		ans[x] = 1;
		fn[0][x] = 1;
		fn[1][x] = 0;
		return ;
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j <= child.size(); j++) {
			mem[i][j] = -1;
		}
	}
	fn[0][x] = dp(0, 0);
	fn[1][x] = dp(0, 1);
	ans[x] = fn[1][x];

	long long var = 1;
	for(auto i : child) {
		var *= ans[i];
		var %= mod;
	} 
	ans[x] += var;
	ans[x] %= mod;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].push_back(q);
		g[q].push_back(p);
	}
	dfs(1, 0);
	printf("%lld\n", ans[1]);
	return 0;
}