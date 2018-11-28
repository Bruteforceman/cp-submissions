#include "bits/stdc++.h"
using namespace std;

int ceiling(int x, int y) {
	return (x + y - 1) / y;
}

string s;
int p[100010];
int q[100010];

int main(int argc, char const *argv[])
{
	int n;
	cin >> n >> s;
	s = "&" + s + "&";
	map <char, int> mp;

	for(int i = 1; i <= n; i++) {
		if(s[i] == s[i - 1]) {
			p[i] = p[i - 1] + 1;
		} else {
			p[i] = 1;
		}
		mp[s[i]] += 1; 
	}
	for(int i = n; i >= 1; i--) {
		if(s[i] == s[i + 1]) {
			q[i] = q[i + 1] + 1;
		} else {
			q[i] = 1;
		}
	} 
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'G') ans = max(ans, p[i]);
		if(s[i] != s[i + 1] && s[i] != s[i - 1] && s[i + 1] == 'G') {
			ans = max(ans, min(mp[s[i - 1]], p[i - 1] + q[i + 1] + 1));
		}
		if(s[i] != s[i + 1] && s[i + 1] == 'G') {
			ans = max(ans, min(mp[s[i + 1]], q[i + 1] + 1));
		}
		if(s[i] != s[i - 1] && s[i - 1] == 'G') {
			ans = max(ans, min(mp[s[i - 1]], p[i - 1] + 1));
		}
	}
	printf("%d\n", ans);
	return 0;
}