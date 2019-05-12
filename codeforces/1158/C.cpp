#include "bits/stdc++.h"
using namespace std;
set <int> alive;
int nxt[500010];
vector <int> g[500010];
int p[500010];
int ord[500010];
int cur;

const int inf = 1e9;

void dfs(int x) {
	alive.erase(x);
	for(int i : g[x]) {
		if(alive.find(i) != alive.end()) {
			dfs(i);
		}
	}
	while(nxt[x] != -1) {
		auto it = alive.upper_bound(x);
		if(it == alive.end() || *it >= nxt[x]) {
			break;
		}
		dfs(*it);
	}
	p[++cur] = x;
}

void solve() {
	int n;
	scanf("%d", &n);
	alive.clear();
	for(int i = 0; i <= n + 1; i++) {
		g[i].clear();
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &nxt[i]);
		alive.insert(i);
		if(nxt[i] != -1) {
			g[nxt[i]].emplace_back(i);
		}
	}
	cur = 0;
	for(int i = 1; i <= n; i++) {
		if(alive.find(i) != alive.end()) {
			dfs(i);
		}
	}
	for(int i = 1; i <= n; i++) {
		// printf("%d ", ord[i]);
		ord[p[i]] = i;
	}
	// printf("\n");

	vector <int> v;
	v.emplace_back(n + 1);
	ord[n + 1] = inf;
	bool bad = false;
	for(int i = n; i >= 1; i--) {
		while(ord[v.back()] < ord[i]) {
			v.pop_back();
		}
		if(nxt[i] != -1 && nxt[i] != v.back()) {
			bad = true;
			break;
		}
		v.emplace_back(i);
	}
	if(bad) {
		printf("-1\n");
	} else {
		for(int i = 1; i <= n; i++) {
			printf("%d ", ord[i]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}