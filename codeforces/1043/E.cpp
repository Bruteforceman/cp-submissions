#include "bits/stdc++.h"
using namespace std;
vector <int> g[300010];
int x[300010], y[300010];
int order[300010];

long long ans[300010];

bool cmp(int p, int q) {
	return x[p] - y[p] > x[q] - y[q];
}
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		order[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		p--;
		q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}

	sort(order, order + n, cmp);

	set <int> s;
	long long sum = 0;
	int cnt = 0;

	for(int h = 0; h < n; h++) {
		int i = order[h];
		long long tot = sum;
		int var = cnt;
		for(int j : g[i]) {
			if(s.find(j) != s.end()) {
				tot -= y[j];
				var -= 1;
			}
		}
		ans[i] += 1LL * var * x[i] + tot;
		// cout << ans[i] << " " << i+1 << " " << sum << endl;
		sum += y[i];
		cnt += 1;
		s.insert(i);
	}
	// exit(0);
	reverse(order, order + n);
	s.clear();
	sum = 0;
	cnt = 0;
	for(int h = 0; h < n; h++) {
		int i = order[h];
		long long tot = sum;
		int var = cnt;
		for(int j : g[i]) {
			if(s.find(j) != s.end()) {
				tot -= x[j];
				var -= 1;
			}
		}
		ans[i] += 1LL * var * y[i] + tot;
		sum += x[i];
		cnt += 1;
		s.insert(i);
	}
	for(int i = 0; i < n; i++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}