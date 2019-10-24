#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int cnt = 0;
		char last = '?';
		set <char> ls;
		for(int i = 0; i < s.size(); i++) {
			if(last == s[i]) {
				++cnt;
			} else {
				if(cnt & 1) ls.insert(last);
				cnt = 1;
				last = s[i];
			}
		}
		if(cnt & 1) ls.insert(last);
		for(char c : ls) cout << c;
		cout << endl;
	}
	return 0;
}