#include "bits/stdc++.h"
using namespace std;
// int a[300010];

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	long long black = 0, white = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(i % 2 == 0) {
			black += (x / 2);
			white += (x + 1) / 2;
		} else {
			black += (x + 1) / 2;
			white += (x / 2);
		}
	}
	cout << min(black, white) << endl;
	return 0;
}