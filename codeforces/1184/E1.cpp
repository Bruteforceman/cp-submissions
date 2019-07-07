#include "bits/stdc++.h"
using namespace std;
int par[100010];
int root(int x) {
	if(par[x] == x) return x;
	return par[x] = root(par[x]);
}
void join(int x, int y) {
	x = root(x);
	y = root(y);
	if(x != y) {
		par[x] = y;
	}
}
vector <int> g[100010];
int l[1000010], r[1000010], w[1000010];
int order[1000010];
bool mst[1000010];

bool cmp(int i, int j) {
	return w[i] < w[j];
}

int anc[20][100010];
int opt[20][100010];
const int logn = 19;
int dep[100010];
int ans[100010];

void dfs(int x, int par) {
	anc[0][x] = par;
	for(auto e : g[x]) {
		int i = l[e] ^ r[e] ^ x;
		if(i != par) {
			dep[i] = 1 + dep[x];
			opt[0][i] = w[e];
			dfs(i, x);
		}
	}
}

int lca(int p, int q) {
	if(dep[p] > dep[q]) swap(p, q);
	int ans = 0;
	for(int i = logn; i >= 0; i--) {
		if(dep[q] - (1 << i) >= dep[p]) {
			ans = max(ans, opt[i][q]);
			q = anc[i][q];
		}
	}
	if(p == q) return ans;
	for(int i = logn; i >= 0; i--) {
		if(anc[i][p] != anc[i][q]) {
			ans = max(ans, opt[i][p]);
			ans = max(ans, opt[i][q]);
			p = anc[i][p]; q = anc[i][q];
		}
	}
	ans = max(ans, opt[0][p]);
	ans = max(ans, opt[0][q]);
	return ans;
}

vector <int> v[100010];
typedef pair <int, int> pii;

void solve(int x, int par, set <pii> &s) {
	for(auto i : v[x]) {
		s.insert(pii(w[i], i));
	}
	for(auto e : g[x]) {
		int i = l[e] ^ r[e] ^ x;
		if(e != par) {
			set <pii> t;
			solve(i, e, t);
			if(t.size() > s.size()) t.swap(s);
			for(auto j : t) {
				if(s.find(j) == s.end()) {
					s.insert(j);
				} else {
					s.erase(j);
				}
			}
		}
	}
	if(s.empty()) {
		ans[par] = 1000000000;
	} else {
		ans[par] = s.begin() -> first;
	}
} 

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &l[i], &r[i], &w[i]);
		order[i] = i;
	}
	sort(order + 1, order + m + 1, cmp);
	for(int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for(int i = 1; i <= m; i++) {
		int x = order[i];
		if(root(l[x]) != root(r[x])) {
			join(l[x], r[x]);
			g[l[x]].push_back(x);
			g[r[x]].push_back(x);
			mst[x] = 1;
		}
	}
	dfs(1, 0);
	for(int i = 1; i <= logn; i++) {
		for(int j = 1; j <= n; j++) {
			anc[i][j] = anc[i - 1][anc[i - 1][j]];
			opt[i][j] = max(opt[i - 1][j], opt[i - 1][anc[i - 1][j]]);
		}
	}
	for(int i = 1; i <= m; i++) {
		if(!mst[i]) {
			ans[i] = lca(l[i], r[i]);
			v[l[i]].push_back(i);
			v[r[i]].push_back(i);
		}
	}
	set <pii> s;
	solve(1, 0, s);

	for(int i = 1; i <= 1; i++) {
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}