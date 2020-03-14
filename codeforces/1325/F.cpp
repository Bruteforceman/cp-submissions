#include "bits/stdc++.h"
using namespace std;
int n, m;
vector <int> g[100010];
int dep[100010];
bool vis[100010];
int par[100010];
int ord[100010];
bool del[100010];

void dfs(int x) {
	vis[x] = true;
	for(auto i : g[x]) {
		if(!vis[i]) {
			dep[i] = 1 + dep[x];
			par[i] = x;
			dfs(i);
		} else {
			int sz = dep[x] - dep[i] + 1;
			if(1LL * sz * sz >= n) {
				puts("2");
				printf("%d\n", sz);
				while(x != i) {
					printf("%d ", x);
					x = par[x];
				}
				printf("%d\n", i);
				exit(0);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++) {
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, [&] (int i, int j) { return dep[i] > dep[j]; });

	vector <int> ind;
	for(int i = 1; i <= n; i++) {
		int x = ord[i];
		if(del[x]) continue;
		ind.push_back(x); 
		for(int j : g[x]) {
			del[j] = true;
		}
		if(1LL * ind.size() * ind.size() >= n) break;
	}
	puts("1");
	for(int i : ind) printf("%d ", i);
	printf("\n");
	return 0;
}