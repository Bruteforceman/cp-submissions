#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
const int mod = 998244353;
string s;
int a[100010];
int n;
long long mem[4][100010];
const long long inf = 1e18;
string H = "hard";


long long dp(int cur, int sub) {
	if(sub >= 4) return inf;
	if(cur == n) {
		return 0;
	}
	if(mem[sub][cur] != -1) return mem[sub][cur];
	long long ans = inf;
	if(s[cur] == H[sub]) {
		ans = min(ans, dp(cur + 1, sub + 1));
		ans = min(ans, dp(cur + 1, sub) + a[cur]);
	} else {
		ans = min(ans, dp(cur + 1, sub));
	}
	return mem[sub][cur] = ans;
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(mem, -1, sizeof mem);
	cout << dp(0, 0) << endl;
	return 0;
}