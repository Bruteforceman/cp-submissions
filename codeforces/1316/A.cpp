#include "bits/stdc++.h"
using namespace std;
int a[1005];

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << min(accumulate(a, a + n, 0), m) << endl;
	}
	return 0;
}