#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
string get(string s, int k) {
	string t = "";
	string p = "";
	for(int i = 0; i < s.size(); i++) {
		if(i >= k) t += s[i];
		else p += s[i];
	}
	if(t.size() & 1) reverse(p.begin(), p.end());
	return t + p;
}
int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		int n;
		cin >> n >> s;
		int ans = 0;
		string opt = s;
		for(int i = 1; i < n; i++) {
			string t = get(s, i);
			if(t < opt) {
				opt = t;
				ans = i;
			}
		}
		cout << opt << endl;
		cout << (ans + 1) << endl;
	}
	return 0;
}