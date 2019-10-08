#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		long long a, b;
		cin >> a >> b;
		long long diff = abs(a - b);
		if(diff == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}