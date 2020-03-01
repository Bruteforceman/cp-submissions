#include "bits/stdc++.h"
using namespace std;
vector <int> g[200010], t[200010];
int a[200010];
int d[200010];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].push_back(q);
		t[q].push_back(p);
	}
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= k; i++) {
		scanf("%d", a + i);
	}
	fill(d, d + n + 1, -1);

	queue <int> Q;
	Q.push(a[k]);
	d[a[k]] = 0;
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(int i : t[x]) {
			if(d[i] == -1) {
				d[i] = 1 + d[x];
				Q.push(i);
			}
		}
	}
	int low = 0, high = 0;
	for(int i = 1; i < k; i++) {
		if(d[a[i]] != (d[a[i + 1]] + 1)) ++low;
		int cnt = 0;
		for(auto x : g[a[i]]) {
			if(d[a[i]] == (1 + d[x])) {
				++cnt;
			}
		}
		if(cnt > 1 || d[a[i]] != (d[a[i + 1]] + 1)) {
			++high;
		}
	}
	printf("%d %d\n", low, high);
	return 0;
}