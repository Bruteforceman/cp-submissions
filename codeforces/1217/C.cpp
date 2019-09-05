#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		int zero = 0;
		int ans = 0;

		for(int i = 0; i < n; i++) {
			if(s[i] == '0') ++zero;
			else {
				int value = 0;
				for(int j = 0; j < 20 && i + j < n; j++) {
					value *= 2;
					value += s[i + j] - '0';
					if(zero + (j + 1) >= value && value >= (j + 1)) {
						++ans;
					}
				}
				zero = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}