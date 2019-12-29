#include "bits/stdc++.h"
using namespace std;
typedef pair <int, int> pii;
pair <int, int> ask(vector <int> v) {
	cout << "?";
	for(auto i : v) {
		cout << " " << i;
	}
	cout << endl;
	int pos, val;
	cin >> pos >> val;
	return make_pair(pos, val);
}
int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	vector <int> v;
	for(int i = 1; i <= k; i++) {
		v.push_back(i);
	}
	pii p = ask(v);
	v.erase(find(v.begin(), v.end(), p.first));
	v.push_back(k + 1);
	pii q = ask(v);
	v.pop_back();
	v.push_back(p.first);

	int cnt = 0;
	for(auto i : v) {
		if(i == p.first) continue;
		vector <int> u;
		for(auto j : v) {
			if(i != j) u.push_back(j);
		}
		u.push_back(k + 1);
		pii r = ask(u);
		if(r.first == p.first) ++cnt;
	}
	if(q.second < p.second) {
		cout << "! " << cnt + 1 << endl;
	} else {
		cout << "! " << k - cnt << endl;
	}
	return 0;
}