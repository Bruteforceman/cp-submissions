#include "bits/stdc++.h"
using namespace std;

int solve(int x) {
	int d = __gcd(180, x);
	int opt = 180 / d;
	for(int i = opt; i <= 998244353; i += opt) {
		if(180LL * (i - 2) >= 1LL * i * x) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while(t--) {
		int ang;
		cin >> ang;
		cout << solve(ang) << endl;
	}
	return 0;
}