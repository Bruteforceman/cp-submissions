#include "bits/stdc++.h"
using namespace std;
int l[300010], r[300010];
vector <int> g[300010];
int in[300010];
int n, m;
int cnt[2][300010];
const int inf = 1e8;

void solve(int c) {
	for(int i = 1; i <= n; i++) {
		g[i].clear();
		in[i] = 0;
	}
	for(int i = 1; i <= m; i++) {
		if(c == 0) {
			g[l[i]].push_back(r[i]);
			++in[r[i]];
		} else {
			g[r[i]].push_back(l[i]);
			++in[l[i]];
		}
	}
	int alive = n;
	vector <int> Q;
	for(int i = 1; i <= n; i++) {
		if(in[i] == 0) {
			Q.push_back(i);		
			--alive;
		}
	}
	while(!Q.empty()) {
		int x = Q.back();
		Q.pop_back();
		if(Q.size() == 0) {
			cnt[c][x] = alive;
		} else if (Q.size() == 1) {
			int y = Q.back();
			bool bad = false;
			for(auto j : g[y]) {
				if(in[j] == 1) {
					bad = true;
					break;
				}
			}
			if(!bad) {
				cnt[c][x] = alive;
			} else {
				cnt[c][x] = -inf;
			}
		} else {
			cnt[c][x] = -inf;
		}
		for(auto j : g[x]) {
			--in[j];
			if(in[j] == 0) {
				Q.emplace_back(j);
				--alive;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}		
	solve(0);
	solve(1);

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		assert(cnt[0][i] + cnt[1][i] < n);
		if(cnt[0][i] + cnt[1][i] >= n-2) {
			// cout << i << endl;
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}