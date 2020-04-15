#include "bits/stdc++.h"
using namespace std;
using pii = pair <int, int>;
const int maxn = 200010;
vector <int> g[maxn];
int sub[maxn];
int dep[maxn];
int cnt[maxn];
int par[maxn];

void dfs(int x, int p) {
	par[x] = p;
	for(auto i : g[x]) {
		if(i != p) {
			dep[i] = 1 + dep[x];
			dfs(i, x);
			sub[x] += 1 + sub[i];
		}
	}
	cnt[x] = sub[x];
}
int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].emplace_back(q);
		g[q].emplace_back(p);
	}
	dfs(1, 0);
	priority_queue <pii> Q;
	for(int i = 1; i <= n; i++) {
		if(cnt[i] == 0) {
			Q.push(pii(dep[i] - sub[i], i));
		}
	}
	long long ans = 0;
	for(int i = 1; i <= k; i++) {
		pii p = Q.top();
		Q.pop();
		ans += p.first;
		cnt[par[p.second]] -= sub[p.second] + 1;
		if(cnt[par[p.second]] == 0) {
			int x = par[p.second];
			Q.push(pii(dep[x] - sub[x], x));
		} 
	}
	printf("%lld\n", ans);
	return 0;
}