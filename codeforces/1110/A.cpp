#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int b, k, ans = 0;
	cin >> b >> k;
	for(int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		x &= 1;
		if(i == k) {
			ans ^= x;
		} else {
			if(b & 1) {
				ans ^= x;
			}
		}
	}
	if(ans) cout << "odd" << endl;
	else cout << "even" << endl;
	return 0;
}