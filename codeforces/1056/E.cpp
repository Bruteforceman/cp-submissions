#include "bits/stdc++.h"
using namespace std;
string s, t;
long long p[1000010];
long long pw[1000010];
const int base = 129;
const int mod = 1000000000 + 7;
int n, m;
int Z, O;
int first;

inline long long value(int i, int j) {
	return (p[j] + mod - ((p[i - 1] * pw[j - i + 1]) % mod)) % mod;
}
bool good(int p) {
	if(n <= 1LL * p * Z) {
		return false;
	}
	int z = p;
	int o = (n - z * Z) / O;
	
	if(o <= 0 || z <= 0) return false;
	if((o * O) + (z * Z) != n) return false;
	long long ho;
	long long hz;
	hz = value(1, z);
	ho = value(z * first + 1, z * first + o);
	if(hz == ho) return false;
	long long ans = 0;
	for(int i = 1; i <= m; i++) {
		if(t[i] == '1') {
			ans *= pw[o];
			ans += ho;
			ans %= mod;
		} else {
			ans *= pw[z];
			ans += hz;
			ans %= mod;
		}
	}
	return ans == value(1, n);
}

int main(int argc, char const *argv[])
{
	pw[0] = 1;
	for(int i = 1; i <= 1000000; i++) {
		pw[i] = pw[i - 1] * base;
		pw[i] %= mod;
	}
	ios_base :: sync_with_stdio (false);
	cin.tie (0);
	cin >> t >> s;
	n = s.size();
	m = t.size();

	s = "&" + s;
	t = "&" + t;

	for(int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * base + s[i];
		p[i] %= mod;
	}
	if(t[1] == '1') {
		for(int i = 1; i <= m; i++) {
			if(t[i] == '1') t[i] = '0';
			else t[i] = '1';
		}
	}
	for(int i = 1; i <= m; i++) {
		if(t[i] == '0') ++Z;
		else ++O;
	}
	first = 1;
	for(int i = 2; i <= m; i++) {
		if(t[1] == t[i]) {
			++first;
		} else {
			break;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += good(i);
	}
	cout << ans << '\n';
	return 0;
}