#include "bits/stdc++.h"
using namespace std;
int mem[3005][3005];
string s;
string t;
const int mod = 998244353;

int dp(int len, int suff) {
	if(len == -1) {
		return 1;
	}
	if(mem[len][suff] != -1) return mem[len][suff];
	long long ans = 0;
	if(suff < t.size()) {
		if(s[len] == t[suff]) ans += dp(len - 1, suff + 1);
	} else {
		ans += dp(len - 1, suff);
	} 
	if(suff + len < t.size()) {
		if(s[len] == t[suff + len]) ans += dp(len - 1, suff);
	} else {
		ans += dp(len - 1, suff);
	}
	return mem[len][suff] = ans % mod;
}
// int dp(int i, int j) {
// 	if(j == -1) return 0;
// 	if(mem[i][j] != -1) return mem[i][j];
// 	int ans = dp(i + 1, l[j][j + i - 1]) + dp(i + 1, r[j][j + i - 1]);
// 	return mem[i][j] = ans % mod; 
// }
// int fn(int i, int j) {
// }
int main(int argc, char const *argv[])
{
	cin >> s >> t;
	int ans = 0;
	memset(mem, -1, sizeof mem);
	for(int i = t.size() - 1; i < s.size(); i++) {
		ans += dp(i, 0);
		ans %= mod;
		// cout << dp(i, 0) << endl;
	}
	cout << ans << endl;
	return 0;
}