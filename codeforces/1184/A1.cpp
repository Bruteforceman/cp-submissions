#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	long long r;
	cin >> r;
	r -= 1;
	for(long long i = 1; i * i < r; i++) {
		if(r % i != 0) continue;
		long long d = r / i;
		if((i % 2) != (d % 2) && i + 1 < d) {
			cout << i << " " << ((d - i - 1) / 2) << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
	return 0;
}