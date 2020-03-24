#include "bits/stdc++.h"
using namespace std;
int a[555];
int dp[2][555][555];

int main(int argc, char const *argv[])
{
	int n, m, b, mod;
	cin >> n >> m >> b >> mod;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0][0][0] = 1;
	int cur = 0;
	for(int i = 1; i <= n; i++) {
		cur ^= 1;
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= b; k++) {
				dp[cur][j][k] = dp[cur ^ 1][j][k];
				if(j > 0 && k >= a[i]) dp[cur][j][k] += dp[cur][j - 1][k - a[i]];
				dp[cur][j][k] %= mod;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= b; i++) {
		ans += dp[cur][m][i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}