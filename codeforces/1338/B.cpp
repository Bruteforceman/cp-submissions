#include "bits/stdc++.h"
using namespace std;
vector <int> g[100010];
int dist[100010];
int cnt;

void dfs(int x, int par) {
	bool leaf = false;
	for(auto i : g[x]) {
		if(i == par) continue;
		if(g[i].size() == 1) {
			if(!leaf) ++cnt;
			leaf = true;
		} else {
			++cnt;
		}
		dist[i] = 1 ^ dist[x];
		dfs(i, x);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].push_back(q);
		g[q].push_back(p);
	}
	int root = 1;
	while(g[root].size() == 1) {
		++root;
	}
	dfs(root, 0);
	set <int> s;
	for(int i = 1; i <= n; i++) {
		if(g[i].size() == 1) {
			s.insert(dist[i]);
		}
	}
	printf("%d %d\n", 2 * (int) s.size() - 1, cnt);
	return 0;
}