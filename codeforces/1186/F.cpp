#include "bits/stdc++.h"
using namespace std;
int l[2000010], r[2000010];
vector <int> g[1000010];
int deg[1000010];
int degn[1000010];

bool del[2000010];
vector <int> order;
vector <int> cont;
vector <int> ans;

void dfs(int x) {
	while(!g[x].empty()) {
		int p = g[x].back();
		g[x].pop_back();
		if(del[p]) continue;
		del[p] = true;
		dfs(l[p] ^ r[p] ^ x);
		order.push_back(p);
	}
} 

void assign() {
	int sz = cont.size();
	for(int i = 0; i < sz; i++) {
		if(i % 2 == 0 || i == sz - 1) {
			ans.push_back(cont[i]);
		}
	}
	cont.clear();	
}

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &l[i], &r[i]);
		g[l[i]].emplace_back(i);
		g[r[i]].emplace_back(i);
		++deg[l[i]];
		++deg[r[i]];
	}
	vector <int> odd;
	for(int i = 1; i <= n; i++) {
		if(deg[i] & 1) {
			odd.push_back(i);
		}
	}
	int cur = m;
	for(int i = 1; i < odd.size(); i += 2) {
		++cur;
		l[cur] = odd[i - 1];
		r[cur] = odd[i];
		g[l[cur]].emplace_back(cur);
		g[r[cur]].emplace_back(cur);
	}
	for(int x = 1; x <= n; x++) {
		order.clear();
		dfs(x);
		int start = 0;
		for(int i = 0; i < order.size(); i++) {
			if(order[i] > m) {
				start = i;
				break;
			}
		}
		for(int i = 0; i < order.size(); i++) {
			int idx = (i + start) % order.size();
			if(order[idx] > m) {
				assign();
			} else {
				cont.push_back(order[idx]);
			}
		} 
		assign();
	}
	printf("%d\n", (int) ans.size());
	assert(ans.size() * 2 <= (n + m));
	for(int i : ans) {
		printf("%d %d\n", l[i], r[i]);
		++degn[l[i]];
		++degn[r[i]];
	}
	for(int i = 1; i <= n; i++) {
		assert(degn[i] * 2 >= deg[i]);
	}
	return 0;	
}