#include "bits/stdc++.h"
using namespace std;
int a[111];

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	for(int i = 0; i < m && i <= n; i++) {
		for(int j = 0; j < m && j <= n; j++) {
			if(((i * i) + (j * j)) % m == 0) {
				// cout << i << ' ' << j << endl;
				long long p = (((n - i) / m) + 1);
				long long q = (((n - j) / m) + 1);
				if(i == 0) --p;
				if(j == 0) --q;
				ans += p * q;
			}
		}
	}
	cout << ans << endl;
	return 0;
}