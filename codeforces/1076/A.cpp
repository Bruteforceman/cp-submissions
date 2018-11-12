#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	string s;
	int n;
	cin >> n;
	cin >> s;
	int rem = n-1;

	for(int i = 0; i < n-1; i++) {
		if(s[i] > s[i+1]) {
			rem = i;
			break;
		}
	}

	for(int i = 0; i < n; i++) {
		if(i != rem) {
			cout << s[i];
		}
	}
	cout << '\n';
	return 0;
}