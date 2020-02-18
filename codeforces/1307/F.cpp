#include "bits/stdc++.h"
using namespace std;
const int maxn = 400010;
const int logn = 19;
int n, k;
vector <int> g[maxn];
int dp[20][maxn], dep[maxn];
bool mark[maxn];
int d[maxn];
int close[maxn];

int par[maxn];
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

void bfs() {
	for(int i = 1; i <= n; i++) {
		par[i] = i;
		d[i] = -1;
	}
	queue <int> Q;
	for(int i = 1; i <= n; i++) {
		if(mark[i]) {
			Q.push(i);
			d[i] = 0;
			close[i] = i;
		}
	}
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		if(d[x] == k) continue;
		for(int i : g[x]) {
			if(d[i] == -1) {
				Q.push(i);
				d[i] = d[x] + 1;
				close[i] = close[x];
			} 
			join(close[x], close[i]);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(d[i] != -1) {
			join(i, close[i]);
		}
	}
}

void dfs(int x, int prev) {
	dp[0][x] = prev;
	for(auto i : g[x]) {
		if(i != prev) {
			dep[i] = 1 + dep[x];
			dfs(i, x);
		}
	}
}

void addEdge(int x, int y) {
	// cout << x << ' ' << y << endl;
	g[x].push_back(y);
	g[y].push_back(x);
}
int lift(int x, int k) {
	for(int i = logn; i >= 0; i--) {
		if(k >= (1 << i)) {
			x = dp[i][x];
			k -= 1 << i;
		}
	}
	return x;
}
int lca(int x, int y) {
	if(dep[x] > dep[y]) swap(x, y);
	y = lift(y, dep[y] - dep[x]);
	if(x == y) return x;
	for(int i = logn; i >= 0; i--) {
		if(dp[i][x] != dp[i][y]) {
			x = dp[i][x];
			y = dp[i][y];
		}
	}
	return dp[0][x];
}
int distance(int p, int q) {
	return dep[p] + dep[q] - 2 * dep[lca(p, q)];
}
int kthNode(int p, int q, int k) {
	int anc = lca(p, q);
	int dist = dep[p] + dep[q] - 2 * dep[anc];
	if(dep[p] - dep[anc] >= k) {
		return lift(p, k);
	} else {
		return lift(q, dist - k);
	}
} 
int main(int argc, char const *argv[])
{
	int r;
	scanf("%d %d %d", &n, &k, &r);
	int tmp = n;
	for(int i = 1; i < tmp; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		addEdge(p, ++n);
		addEdge(q, n);
	}
	for(int i = 1; i <= r; i++) {
		int x;
		scanf("%d", &x);
		mark[x] = 1;
	}
	bfs();
	dfs(1, 0);
	for(int i = 1; i <= logn; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(distance(x, y) <= 2 * k) printf("YES\n");
		else {
			int a = kthNode(x, y, k);
			int b = kthNode(y, x, k);
			// cout << a << " qq " << b << endl;
			if(root(a) == root(b)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} 
	}
	return 0;
}