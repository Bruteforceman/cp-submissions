#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	long long n;
	cin >> n;

	if(n & 1) {
		long long d = n;
		for(long long i = 2; i * i <= n; i++) {
			if(n % i == 0) {
				d = i;
				break;
			}
		}
		n -= d;
		cout << 1 + (n / 2) << endl;
	} else {
		cout << (n / 2) << endl;
	}
	return 0;
}