#include "bits/stdc++.h"
using namespace std;
int c[2005];
vector <int> g[2005];
int ans[2005];
int sub[2005];

void add(int x, int val) {
	ans[x] += val;
	for(auto i : g[x]) {
		add(i, val);
	}
}
void addGreater(int x, int val) {
	if(ans[x] >= val) {
		++ans[x];
	}
	for(auto i : g[x]) {
		addGreater(i, val);
	}
}
void dfs(int x) {
	for(auto i : g[x]) {
		dfs(i);
		add(i, sub[x]);
		addGreater(i, c[x] + 1);
		sub[x] += sub[i];
	}
	sub[x] += 1;
	ans[x] = c[x] + 1;
	if(sub[x] <= c[x]) {
		printf("NO\n");
		exit(0);
	}
}

int main(int argc, char const *argv[])
{	
	int n;
	scanf("%d", &n);
	int root = 1;
	for(int i = 1; i <= n; i++) {
		int p;
		scanf("%d %d", &p, &c[i]);
		if(p == 0) {
			root = i;
		} else {
			g[p].push_back(i);
		}
	}
	dfs(root);
	printf("YES\n");
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	return 0;
}