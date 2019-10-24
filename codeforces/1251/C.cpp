#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector <char> p, q;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] & 1) p.push_back(s[i]);
			else q.push_back(s[i]);
		}
		reverse(p.begin(), p.end());
		reverse(q.begin(), q.end());
		while(!p.empty() || !q.empty()) {
			if(p.empty()) {
				cout << q.back();
				q.pop_back();
			}
			else if (q.empty()) {
				cout << p.back();
				p.pop_back();
			}
			else if (p.back() < q.back()) {
				cout << p.back();
				p.pop_back();
			} else {
				cout << q.back();
				q.pop_back();
			}
		}
		cout << endl;
	}
	return 0;
}