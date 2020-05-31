#include "bits/stdc++.h"
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn], c[maxn];
vector <int> g[maxn];
int p[maxn], q[maxn];
long long ans;

void dfs(int x, int par, int opt) {
	if(b[x] != c[x]) {
		if(b[x] == 0) p[x] = 1;
		else q[x] = 1;
	}
	for(auto i : g[x]) {
		if(i != par) {
			dfs(i, x, min(opt, a[i]));
			p[x] += p[i];
			q[x] += q[i];
		}
	}
	int var = min(p[x], q[x]);
	ans += 2LL * var * opt;
	p[x] -= var;
	q[x] -= var;
}
void solve() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", a + i, b + i, c + i);
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0, a[1]);
	if(p[1] == 0 && q[1] == 0) {
		printf("%lld\n", ans);
	} else {
		printf("-1\n");
	}
}

int main(int argc, char const *argv[])
{
	int t = 1;
	while(t--) {
		solve();
	}
	return 0;
}