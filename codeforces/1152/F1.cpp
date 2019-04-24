#include "bits/stdc++.h"
using namespace std;
long long dp[2][1 << 4][15][15];
int n, m, k;
const int mod = 1000000000 + 7;

int main(int argc, char const *argv[])
{
	cin >> n >> k >> m;
	int mask = (1 << m) - 1;

	int i = 0;
	dp[i][0][0][1] = 1;

	for(int cur = n; cur >= 1; cur--) {
		i ^= 1;
		for(int j = 0; j < (1 << m); j++) {
			for(int x = 0; x <= k; x++) {
				for(int y = 0; y <= k; y++) {
					int nm = j;
					nm = (nm << 1);
					dp[i][j][x][y] = 0;
					if(nm <= mask) {
						dp[i][j][x][y] += dp[i ^ 1][nm][x][y];
					}
					for(int opt = 0; opt < m; opt++) {
						if((j >> opt) & 1) {
							nm = j;
							nm ^= 1 << opt;
							nm = (nm << 1) | 1;
							if(x > 0 && nm <= mask) {
								dp[i][j][x][y] += dp[i ^ 1][nm][x - 1][y];
								dp[i][j][x][y] += dp[i ^ 1][nm ^ 1][x - 1][y];
								if(y > 0) {
									dp[i][j][x][y] += dp[i ^ 1][nm ^ 1][x - 1][y - 1] * (y - 1); 
								}
							}
						}
					}
					nm = j;
					nm = (nm << 1) | 1;
					if(x > 0 && nm <= mask) {
						dp[i][j][x][y] += dp[i ^ 1][nm][x - 1][y + 1];
						dp[i][j][x][y] += dp[i ^ 1][nm ^ 1][x - 1][y] * y;
						dp[i][j][x][y] += dp[i ^ 1][nm ^ 1][x - 1][y + 1];
					}
					dp[i][j][x][y] %= mod;
				}
			}
		}
	}
	long long ans = dp[i][0][k][0];
	printf("%lld\n", ans);
	return 0;
}