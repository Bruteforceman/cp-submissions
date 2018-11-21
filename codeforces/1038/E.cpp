#include "bits/stdc++.h"
using namespace std;
typedef pair <int, int> pii;
vector <pii> g[6];
const int inf = 1e9;
int loop[5];
int mem[5][105][1 << 4][1 << 4][2];

int dp(int node, int edge, int deg, int mask, int take) {
	if(edge == g[node].size()) {
		if (__builtin_popcount(mask) == 4 || take == 0) {
			if(__builtin_popcount(deg) == 2 || __builtin_popcount(deg) == 0) {
				return take ? loop[node] : 0;
			} else {
				return -inf;
			}
		}
		else {
			int ans = -inf;
			for(int i = 0; i < 4; i++) {
				if((mask >> i) & 1) continue;
				ans = max(ans, dp(i, 0, deg, mask ^ (1 << i), 0));
			}
			return ans + loop[node];
		}
	}
	if(mem[node][edge][deg][mask][take] != -1) return mem[node][edge][deg][mask][take];
	int ans = -inf;
	int p = g[node][edge].first;
	int q = g[node][edge].second;
	if((mask >> p) & 1) ans = max(ans, dp(node, edge + 1, deg ^ (1 << p) ^ (1 << node), mask, 1) + q);
	ans = max(ans, dp(node, edge + 1, deg, mask, take));
	return mem[node][edge][deg][mask][take] = ans;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int p, q, r;
		scanf("%d %d %d", &p, &r, &q);
		--p;
		--q;
		if(p != q){
			g[p].push_back(pii(q, r));
			g[q].push_back(pii(p, r));
		} else {
			loop[p] += r;
		}
	}
	memset(mem, -1, sizeof mem);
	int ans = 0;
	for(int i = 0; i < 4; i++) {
		ans = max(ans, dp(i, 0, 0, 1 << i, 1));
	}
	printf("%d\n", ans);
	return 0;
}