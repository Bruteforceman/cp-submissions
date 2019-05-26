#include "bits/stdc++.h"
using namespace std;
vector <string> v;
string s;
void gen() {
	if(s.size() > 0) {
		v.push_back(s);
	}
	for(char c : {'0', '1'}) {
		s += c;
		bool good = true;
		int sz = s.size();
		for(int i = sz - 3; i >= 0; i -= 2) {
			if(s[sz - 1] == s[i] && s[i] == s[(sz - 1 + i) / 2]) {
				good = false;
				break;
			}
		}
		if(good) {
			gen();
		}
		s.pop_back();
	}
}

string txt;

int count(int id) {
	int cnt = 0;
	for(int i = 0; i < txt.size(); i++) {
		bool match = true;
		if(i + v[id].size() <= txt.size()) {
			for(int j = 0; j < v[id].size(); j++) {
				if(txt[i + j] != v[id][j]) {
					match = false;
					break;
				}
			}
			cnt += match;
		} else break;
	}	
	return cnt;
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	gen();
	cin >> txt;
	int len = txt.size();
	long long ans = ((1LL * len * (len + 1))) / 2;
	for(int i = 0; i < v.size(); i++) {
		ans -= count(i); 		
	}
	cout << ans << endl;
	return 0;
}