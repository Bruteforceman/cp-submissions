#include "bits/stdc++.h"
using namespace std;
const int mod = 998244353;
long long dp[2005][2005];
long long fac[2005];

int a[2005][2005];
int p[2][2005];

int n;

struct tree {
	int t[2005];
	void clear() {
		memset(t, 0, sizeof t);
	}
	void update(int x, int val) {
		for(int i = x; i <= n; i += i & (-i)) {
			t[i] += val;
		}
	}
	int query(int x) {
		int ans = 0;
		for(int i = x; i > 0; i -= i & (-i)) {
			ans += t[i];
		}
		return ans;
 	}
} T, P, Q;

int main(int argc, char const *argv[])
{
	dp[0][0] = 1;
	fac[0] = 1;
	for(int i = 1; i <= 2000; i++) {
		for(int j = 0; j <= i; j++) {
			if(j) {
				dp[i][j] += dp[i - 1][j] * (i - j);
				dp[i][j] += dp[i - 1][j - 1] * j;
			} else {
				dp[i][j] += dp[i - 1][j + 1] * (i - 1);
			}
			dp[i][j] %= mod;
		}
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	long long ans = 0;
	for(int i = 1; i <= 1; i++) {
		Q.clear();
		for(int j = 1; j <= n; j++) {
			Q.update(j, 1);
		}
		for(int j = 1; j <= n; j++) {
			Q.update(a[i][j], -1);
			int cnt = Q.query(a[i][j] - 1);
			ans += fac[n - j] * cnt;
			ans %= mod;
		}
		for(int j = 2; j <= n; j++) {
			ans *= dp[n][0];
			ans %= mod;
		}
	}
	for(int i = 2; i <= n; i++) {
		T.clear();	
		P.clear();
		Q.clear();
		for(int j = 1; j <= n; j++) {
			p[0][a[i - 1][j]] = j;
			p[1][a[i][j]] = j;
		}
		for(int j = 1; j <= n; j++) {
			if(p[1][j] < p[0][j]) {
				T.update(p[1][j] + 1, 1);
				T.update(p[0][j], -1);
			}
			P.update(j, 1);
			Q.update(j, 1);
		}
		long long res = 0;
		for(int j = 1; j <= n; j++) {
			if(P.query(a[i - 1][j]) > P.query(a[i - 1][j] - 1)) {
				P.update(a[i - 1][j], -1);
			}
			if(P.query(a[i][j]) > P.query(a[i][j] - 1)) {
				P.update(a[i][j], -1);
			}
			Q.update(a[i][j], -1);
			int tot = T.query(j);
			int cntbad = P.query(a[i][j] - 1);
			int cntgood = Q.query(a[i][j] - 1) - cntbad;
			if(Q.query(a[i - 1][j]) > Q.query(a[i - 1][j] - 1) && a[i - 1][j] < a[i][j]) {
				--cntgood;
			}
			res += dp[n - j][tot + 1] * cntbad;
			res += dp[n - j][tot] * cntgood;
			res %= mod;
		}
		for(int j = i+1; j <= n; j++) {
			res *= dp[n][0];
			res %= mod;
		}
		ans += res;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}