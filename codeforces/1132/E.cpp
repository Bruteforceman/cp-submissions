#include "bits/stdc++.h"
using namespace std;
long long dp[9][890];
long long C[9];
const int mod = 840;

const long long inf = 1e18;

int main(int argc, char const *argv[])
{
	long long W;
	cin >> W;
	for(int i = 1; i <= 8; i++) {
		cin >> C[i];
	}
	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j < mod; j++) {
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < mod; j++) {
			int id = i + 1;
			long long need = (W - dp[i][j]) / id;
			need = min(C[id], need);
			for(long long x = max(need - mod, 0LL); x <= need; x++) {
				dp[id][(j + x * id) % mod] = max(dp[id][(j + x * id) % mod], dp[i][j] + x*id);
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < mod; i++) {
		ans = max(ans, dp[8][i]);
	}
	cout << ans << endl;
	return 0;
}