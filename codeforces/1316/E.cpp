#include "bits/stdc++.h"
using namespace std;
int s[100010][8];
int a[100010];
int ord[100010];
int n, p, k;
const long long inf = 1e16;
long long mem[1 << 7][100005];

long long dp(int cur, int mask) {
	if(cur == n) {
		return (mask == (1 << p) - 1) ? 0 : -inf;
	}
	if(mem[mask][cur] != -1) return mem[mask][cur];
	long long ans = dp(cur + 1, mask);
	if(cur - __builtin_popcount(mask) < k) ans += a[ord[cur]];
	for(int i = 0; i < p; i++) {
		if((mask >> i) & 1) continue;
		ans = max(ans, dp(cur + 1, mask ^ (1 << i)) + s[ord[cur]][i]);
	}
	return mem[mask][cur] = ans;
}	
int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &n, &p, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		ord[i] = i;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < p; j++) {
			scanf("%d", &s[i][j]);
		}
	}
	sort(ord, ord + n, [&] (int i, int j) { return a[i] > a[j]; });
	memset(mem, -1, sizeof mem);
	printf("%lld\n", dp(0, 0));
	return 0;
}