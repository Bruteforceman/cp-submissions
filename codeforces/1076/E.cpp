#include "bits/stdc++.h"
using namespace std;
typedef pair <int, int> pii;

int n, m;
long long t[300010];
vector <int> g[300010];
vector <pii> v[300010];
long long ans[300010];

void update(int x, int val) {
	for(int i = x; i <= n; i += i & (-i)) {
		t[i] += val;
	} 
}
long long query(int x) {
	long long ans = 0;
	for(int i = x; i > 0; i -= i & (-i)) {
		ans += t[i];
	}	
	return ans;
}

void dfs(int x, int par, int dep) {
	for(auto i : v[x]) {
		update(dep, i.first);
		if(dep + i.second + 1 <= n) update(dep + i.second + 1, -i.first);
	}
	ans[x] = query(dep);
	for(auto i : g[x]) {
		if(i - par) {
			dfs(i, x, dep + 1);
		}
	}
	for(auto i : v[x]) {
		update(dep, -i.first);
		if(dep + i.second + 1 <= n) update(dep + i.second + 1, i.first);
	}
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
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int ver, d, x;
		scanf("%d %d %d", &ver, &d, &x);
		v[ver].emplace_back(x, d);
	}
	dfs(1, 0, 1);

	for(int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}