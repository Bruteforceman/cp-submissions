#include "bits/stdc++.h"
using namespace std;
vector <int> g[100010];
bool bad[100010];
int cnt[100010];
int deg[100010];
bool del[100010];

struct data {
	int node;
	double val;
	data (int node, double val) : node(node), val(val) {}
	data () {}
	bool operator < (data x) const {
		return val > x.val;
	}
};

int main(int argc, char const *argv[])
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		bad[x] = true;
		del[x] = true;
	}	

	for(int i = 1; i <= m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		assert(p != q);
		g[p].emplace_back(q);
		g[q].emplace_back(p);
	}
	priority_queue <data> Q;
	for(int i = 1; i <= n; i++) {
		if(bad[i]) {
			continue;
		}
		for(auto j : g[i]) {
			if(!bad[j]) ++cnt[i];
		}
		deg[i] = g[i].size();
		Q.push(data(i, ((double) cnt[i]) / deg[i]));
	}
	
	vector <data> v;
	while(!Q.empty()) {
		int node = Q.top().node;
		double val = Q.top().val;
		Q.pop();
		if(bad[node]) continue;
		for(auto j : g[node]) {
			if(bad[j]) continue;
			--cnt[j];
			Q.push(data(j, ((double) cnt[j]) / deg[j]));
		} 
		bad[node] = true;
		v.emplace_back(node, val);
	}
	int opt = -1;
	for(int i = 0; i < v.size(); i++) {
		if(opt == -1 || v[i].val > v[opt].val) {
			opt = i;
		}
	}
	for(int i = 0; i < opt; i++) {
		del[v[i].node] = true; 
	}
	vector <int> out;
	for(int i = 1; i <= n; i++) {
		if(!del[i]) {
			out.emplace_back(i);
		}
	}
	printf("%u\n", out.size());
	for(auto i : out) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}