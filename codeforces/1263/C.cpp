#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		set <int> s;
		int p = sqrt(n);
		for(int i = 0; i <= p; i++) s.insert(i);
		for(int i = 1; i <= (p + 1); i++) s.insert(n / i);
		cout << s.size() << endl;
		for(auto i : s) {
			cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}