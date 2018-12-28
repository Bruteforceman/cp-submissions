#include "bits/stdc++.h"
using namespace std;
int P[200010];
int Q[200010];
const int mod = 998244353;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	string s;
	int n;
	cin >> n >> s;
	s = "%" + s + "%";

	P[0] = Q[n+1] = true;
	int cnt1 = 0;
	int cnt2 = 0;

	for(int i = 1; i <= n; i++) {
		if(i == 1 || s[i - 1] == s[i]) {
			P[i] = P[i - 1];
		} else {
			P[i] = false;
		}
	}
	for(int i = n; i >= 1; i--) {
		if(i == n || s[i + 1] == s[i]) {
			Q[i] = Q[i + 1];
		} else {
			Q[i] = false;
		}
	}
	for(int i = 0; i <= n+1; i++) {
		cnt1 += P[i];
		cnt2 += Q[i];
	}
	if(s[1] == s[n]) {
		printf("%lld\n", (1LL * cnt1 * cnt2) % mod);
	} else {
		printf("%d\n", (cnt1 - 1) + (cnt2 - 1) + 1);
	}
	return 0;
}