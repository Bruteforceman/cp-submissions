#include "bits/stdc++.h"
using namespace std;
const int mod = 998244353;
const int maxn = 300000;

int fac[maxn + 10];
int inv[maxn + 10];
int power(int a, int b) {
	if(b < 0) return 0;
	if(b == 0) return 1;
	if(b & 1) return (1LL * power(a, b - 1) * a) % mod;
	int m = power(a, b >> 1);
	return (1LL * m * m) % mod;
}
int inverse(int x) {
	return power(x, mod - 2);
}
int nCr(int n, int r) {
	if(n < r || n < 0) return 0;
	int num = fac[n];
	int den = (1LL * inv[r] * inv[n - r]) % mod;
	return (1LL * num * den) % mod;
}
int main(int argc, char const *argv[])
{
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= maxn; i++) {
		fac[i] = (1LL * fac[i - 1] * i) % mod;
		inv[i] = inverse(fac[i]);
	}	
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	for(int i = 1; i <= m; i++) {
		long long way = 1LL * nCr(i - 1, n - 3) * power(2, n - 3);
		way %= mod;
		way *= (i - 1 - (n - 3));
		ans += way;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}