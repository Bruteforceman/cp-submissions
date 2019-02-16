#include "bits/stdc++.h"
using namespace std;
const int mod = 1000000000 + 7;
const int maxn = 1000000;
long long fac[1000010];
long long inv[1000010];

long long modpow(long long b, long long e) {
	if(e == 0) return 1;
	if(e & 1) return (modpow(b, e - 1) * b) % mod;
	long long m = modpow(b, e >> 1);
	return (m * m) % mod;
}
long long inverse(long long x) {
	return modpow(x, mod - 2);
}
long long nCr(int n, int r) {
	if(r < 0 || n < r) return 0;
	long long num = fac[n];
	long long den = (inv[r] * inv[n - r]) % mod;
	return (num * den) % mod;
} 

int main(int argc, char const *argv[])
{
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= maxn; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
		inv[i] = inverse(fac[i]);
	} 
	int n, a, b, m;
	cin >> n >> m >> a >> b;

	long long ans = 0;
	for(int i = 0; i <= n - 2; i++) {
		int dist = i + 1;
		long long way = nCr(m - 1, dist - 1);
		way *= modpow(n, (n - 1) - (i + 1));
		way %= mod;
		way *= nCr(n - 1, i + 1);
		way %= mod;
		way *= (modpow(m, n-1-dist) * fac[i + 2]) % mod;
		way %= mod;
		ans += way;
		ans %= mod;
	}
	ans *= inverse((1LL * n * (n - 1)) % mod);
	ans %= mod;
	cout << ans << endl;
	return 0;
}