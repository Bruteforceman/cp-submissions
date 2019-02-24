#include "bits/stdc++.h"
using namespace std;
int p[3333];
int dp[3333];
bool bad[3333];

const int mod = 1000000000 + 7;

int solve(string &s) {
	int n = s.size();
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		string cur = "";
		dp[i] = 0;
		for(int j = i - 1; j >= max(0, i - 4); j--) {
			cur += s[j];
			if(cur == "0011" || cur == "0101" || cur == "1110" || cur == "1111") continue;
			dp[i] += dp[j];
			if(dp[i] >= mod) dp[i] -= mod;
		}
	}
	int nxt = -1;
	p[0] = -1;
	for(int i = 0; i < n; i++) {
		bad[i] = false;
	} 
	for(int i = 1; i < n; i++) {
		while(nxt != -1 && s[nxt + 1] != s[i]) {
			nxt = p[nxt];
		}
		if(s[nxt + 1] == s[i]) {
			++nxt;
		}
		p[i] = nxt;
		if(nxt >= 0) {
			bad[nxt] = true;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!bad[i]) {
			ans += dp[i + 1];
			if(ans >= mod) ans -= mod;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int m;
	scanf("%d", &m);
	int ans = 0;
	string s = "";
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if(x == 0) {
			s = "0" + s;
		} else {
			s = "1" + s;
		}
		ans += solve(s);
		if(ans >= mod) ans -= mod;
		printf("%d\n", ans);
	}
	return 0;
}