#include "bits/stdc++.h"
using namespace std;

typedef pair <int, int> pii;

vector <int> g[100010];
int val[100010];
int sub[100010];
vector <int> v;
int ans[100010];
set <int> S[100010];

void dfs(int x) {
	sub[x] = 1;
	if(g[x].empty()) ++val[x];
	for(auto i : g[x]) {
		dfs(i);
		val[x] += val[i];
		sub[x] += sub[i];	
	}
	v.push_back(val[x]);
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		g[p].push_back(i);
	}
	dfs(1);
	int opt = 0;
	sort(v.begin(), v.end());
	int l = 0;
	for(int i = 1; i <= val[1]; i++) {
		while(l < v.size() && v[l] <= i) {
			++l;
			ans[l] = i;
		}
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}