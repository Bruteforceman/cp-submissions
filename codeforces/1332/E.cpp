#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector <int> multiply(vector <int> &a, vector <int> &b) {
	vector <int> ans (2, 0);
	for(size_t i = 0; i < a.size(); i++) {
		for(size_t j = 0; j < b.size(); j++) {
			ans[(i + j) & 1] += (1LL * a[i] * b[j]) % mod;
			ans[(i + j) & 1] %= mod;
		}
	}
	return ans;
}
int main() {
	int n, m, L, R;
	cin >> n >> m >> L >> R;
	vector <int> v (2);
	v[0] = R / 2 - (L - 1) / 2;
	v[1] = R - L + 1 - v[0];
	
	long long k = 1LL * n * m;
	vector <int> ans (2, 0);
	ans[0] = 1;
	for(int i = 0; i < 64; i++) {
		if((k >> i) & 1) ans = multiply(ans, v);
		v = multiply(v, v);
	}
 	if(k % 2 == 0) {
		cout << ans[0] << endl;
	} else {
		cout << (ans[0] + ans[1]) % mod << endl;
	}
}