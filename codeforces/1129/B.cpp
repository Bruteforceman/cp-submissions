#include "bits/stdc++.h"
using namespace std;


int main(int argc, char const *argv[])
{
	int c;
	cin >> c;
	int k = 2000;
	int x = (((k - c) % k) + k) % k;
	long long cur = x;
	while(cur * (k - 1) <= c) {
		cur += k;
	}
	long long y = ((1LL * cur * (k - 1)) - c) / k;
	
	cout << k << endl;
	for(int i = 1; i <= k-2; i++) {
		cout << 0 << ' ';
	}
	cout << -y << ' ' << cur << endl;
	return 0;
}