#include "bits/stdc++.h"
using namespace std;
int p[110];
int mem[2][110][110][110];
const int inf = 100000000;
int n;

int dp(int cur, int odd, int even, int prev) {
	if(odd < 0) return inf;
	if(even < 0) return inf;
	if(cur == n + 1) {
		return 0;
	}
	if(mem[prev][cur][odd][even] != -1) return mem[prev][cur][odd][even];
	int ans = inf;
	if(p[cur] != 0) {
		int par = p[cur] % 2;
		ans = min(ans, dp(cur + 1, odd, even, par) + (prev != par));
	} else {
		ans = min(ans, dp(cur + 1, odd - 1, even, 1) + (prev != 1));
		ans = min(ans, dp(cur + 1, odd, even - 1, 0) + (prev != 0));
	}
	return mem[prev][cur][odd][even] = ans;
}


int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	memset(mem, -1, sizeof mem);
	
	cin >> n;
	set <int> s;
	for(int i = 1; i <= n; i++) {
		s.insert(i);
	}
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		s.erase(p[i]);
	}
	int odd = 0;
	int even = 0;
	for(auto i : s) {
		if(i & 1) ++odd;
		else ++even;
	}
	cout << min(dp(1, odd, even, 1), dp(1, odd, even, 0)) << endl;
	return 0;
}