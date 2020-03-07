#include "bits/stdc++.h"
using namespace std;
int power[500010];
int poly[500010];
int xorh[500010];
int h[500010];
long long c[500010];
bool imp[500010];

const int mod = 1000000000 + 7;
const int base = 131;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	power[0] = 1;
	for(int i = 1; i <= 500000; i++) {
		power[i] = (1LL * power[i - 1] * base) % mod;
	}
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++) {
			scanf("%lld", c + i);
			h[i] = rand();
			xorh[i] = poly[i] = imp[i] = 0;
		}
		for(int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			xorh[v] ^= h[u];
			poly[v] = (poly[v] + power[u]) % mod;
			imp[v] = 1;
		}
		map <pair <int, int>, long long> mp;
		for(int i = 0; i < n; i++) {
			if(imp[i]) {
				mp[make_pair(xorh[i], poly[i])] += c[i];
			}
		}
		long long ans = 0;
		for(auto i : mp) {
			ans = __gcd(ans, i.second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}