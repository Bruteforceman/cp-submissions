#include <bits/stdc++.h>
using namespace std;
int mod;
long long fac[250010];
long long inv[250010];

long long power(long long b, int e) {
	if(e == 0) return 1;
	if(e == 1) return (power(b, e - 1) * b) % mod;
	long long m = power(b, e >> 1);
	return (m * m) % mod;
}
long long inverse(long long x) {
	return power(x % mod, mod - 2);
}

long long nPr(int n, int r) {
	long long num = fac[n];
	long long den = inv[n - r];
	return (num * den) % mod;
} 

int main() {
	int n;
	cin >> n >> mod;
	
	inv[0] = fac[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
		// inv[i] = inverse(fac[i]);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		long long ways = (n - i + 1) * fac[i];
		ways %= mod;
		ways *= (n - i + 1);
		ways %= mod;
		ways *= fac[n - i];
		ways %= mod;
		ans += ways;
		ans %= mod;
	}
	cout << ans << endl;
}