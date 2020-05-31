#include "bits/stdc++.h"
using namespace std;
const int inf = 1e8;
const int maxn = 2e3 + 10;
string s, t;
int p[26][maxn], q[26][maxn];
int mem[maxn][maxn];
int n;
int dp(int x, int y) {
	if(y == n) return 0;
	if(x > n) return inf;
	int &ans = mem[x][y];
	if(ans != -1) return ans;
	ans = 1 + dp(x + 1, y);
	if(s[x] == t[y]) {
		ans = min(ans, dp(x + 1, y + 1));
	}
	int c = t[y] - 'a';
	if(p[c][x] > q[c][y]) ans = min(ans, dp(x, y + 1));
	return ans;
}
void solve() {
	cin >> n;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int cntP[26], cntQ[26];
	memset(cntP, 0, sizeof cntP);
	memset(cntQ, 0, sizeof cntQ);
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 26; j++) {
			p[j][i] = cntP[j];
			q[j][i] = cntQ[j];
		}
		if(i == n) continue;
		cntP[s[i] - 'a'] += 1;
		cntQ[t[i] - 'a'] += 1;
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			mem[i][j] = -1;
		}
	}
	int ans = dp(0, 0);
	if(ans >= inf) ans = -1;
	cout << ans << '\n';
}
int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}