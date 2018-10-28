#include "bits/stdc++.h"
using namespace std;
int a[300010];
int b[300010];
int c[300010];
int aux[300010];
const int maxn = 300000;

long long cnt[300010];
long long dp[300010];

vector <int> v[300010];
int u[300010];
int p[300010];

int mobius(int x) {
	int ans = 1;
	while(x > 1) {
		int q = p[x];
		int tot = 0;
		while(x % q == 0) {
			++tot;
			x /= q;
		}
		if(tot > 1) return 0;
		ans *= -1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	for(int i = 1; i <= maxn; i++) {
		for(int j = i; j <= maxn; j += i) {
			v[j].emplace_back(i);
		}
		p[i] = i;
	}
	for(int i = 2; i <= maxn; i++) {
		if(p[i] == i) {
			for(int j = i; j <= maxn; j += i) {
				p[j] = i;
			}
		}
	}
	for(int i = 1; i <= maxn; i++) {
		u[i] = mobius(i);
	}
	int n;
	scanf("%d", &n);
	int g = 0;

	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		g = __gcd(a[i], g);
		b[a[i]] = 1;
		c[a[i]] = 1;
	}
	if(g > 1) {
		printf("-1\n");
		exit(0);
	}
	if(c[1] == 1) {
		printf("1\n");
		exit(0);
	}
	for(int i = 2; ; i++) {
		memset(cnt, 0, sizeof cnt);
		memset(aux, 0, sizeof aux);
		memset(dp, 0, sizeof dp);
		for(int j = 1; j <= maxn; j++) {
			if(c[j] == 1) {
				for(auto k : v[j]) {
					aux[k] += 1;
				}
			}
		}
		for(int j = 1; j <= maxn; j++) {
			if(b[j] == 1) {
				for(auto k : v[j]) {
					cnt[k] += aux[k];
				}
			}
		}
		for(int j = 1; j <= maxn; j++) {
			for(int k = j; k <= maxn; k += j) {
				dp[j] += u[k / j] * cnt[k];
			}
		}
		// for(int j = 1; j <= maxn; j++) {
		// 	printf("%lld ", cnt[j]);
		// }
		// printf("\n");
		for(int j = 1; j <= maxn; j++) {
			if(dp[j] > 0) {
				c[j] = 1;
				// printf("%d ", j);
			} else {
				c[j] = 0;
			}
		}
		// printf("\n");
		if(c[1] == 1) {
			printf("%d\n", i);
			exit(0);
		}
	}
	return 0;
}