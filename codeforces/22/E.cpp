#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector <int> in (n + 1, 0), root (n + 1, 0), f (n + 1);
	vector <bool> vis (n + 1, false);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		in[f[i]] += 1;
	}
	vector <int> v;
	for(int i = 1; i <= n; i++) {
		int cur = i;
		vector <int> can;
		int mx = 0;
		while(!vis[cur]) {
			can.push_back(cur);
			vis[cur] = true;
			mx = max(mx, in[cur]);
			cur = f[cur];
		}
		if(root[cur] == 0) {
			root[cur] = cur;
			v.push_back(cur);
			if(mx <= 1) in[cur] = 0;
		}
		for(auto x : can) {
			root[x] = root[cur];
		}
	}
	vector <int> nxt (n + 1, 0);
	for(int i = 0; i < v.size(); i++) {
		nxt[v[i]] = v[(i + 1) % v.size()];
	} 
	vector <pair <int, int>> edge;
	for(int i = 1; i <= n; i++) {
		if(in[i] == 0) {
			if(nxt[root[i]] != i) edge.emplace_back(nxt[root[i]], i);
		}
	}
	printf("%d\n", (int) edge.size());
	for(auto i : edge) {
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}