#include "bits/stdc++.h"
using namespace std;
int f[12];

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1; i < 10; i++) {
		cin >> f[i];
	}
	bool good = false;
	for(int i = 0; i < n; i++) {
		int c = s[i] - '0';
		if(good && c > f[c]) break;
		if(c < f[c]) {
			s[i] = f[c] + '0';
			good = true;
		}
	}
	cout << s << endl;
	return 0;
}