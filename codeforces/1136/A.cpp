#include "bits/stdc++.h"
using namespace std;
int l[111], r[111];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}
	int k;
	cin >> k;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(k <= r[i]) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}