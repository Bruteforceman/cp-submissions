#include "bits/stdc++.h"
using namespace std;
int sub[555];
vector <int> done;
typedef pair <int, int> pii;

int par[555];

int query(vector <int> p, vector <int> q, int v) {
	cout << p.size() << endl;
	for(int i = 0; i < p.size(); i++) cout << p[i] << ' ';
	cout << endl;
	cout << q.size() << endl;
	for(int i = 0; i < q.size(); i++) cout << q[i] << ' ';
	cout << endl;
	cout << v << endl;
	int ans;
	cin >> ans;
	return ans;
}
int search(int b, int e, int val) {
	if(b == e) {
		return b;
	}
	int m = (b + e) >> 1;
	vector <int> v;
	for(int i = 0; i <= m; i++) {
		v.emplace_back(done[i]);
	}
	if(query({1}, v, val)) return search(b, m, val);
	else return search(m + 1, e, val);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector <int> v;
	for(int i = 2; i <= n; i++) {
		v.emplace_back(i);
	}
	sub[1] = n;
	for(int i = 2; i <= n; i++) {
		sub[i] = query({1}, v, i);
	}
	vector <pii> A; 
	for(int i = 1; i <= n; i++) {
		A.emplace_back(sub[i], i);
	}
	sort(A.begin(), A.end());
	for(auto i : A) {
		int cur = i.first - 1;
		while(cur > 0 && !done.empty()) {
			int x = search(0, done.size() - 1, i.second);
			par[done[x]] = i.second;
			cur -= sub[done[x]];
			done.erase(done.begin() + x);
		}
		done.emplace_back(i.second);
	}
	cout << "ANSWER" << endl;
	for(int i = 2; i <= n; i++) {
		cout << par[i] << ' ' << i << endl;
	}
	return 0;
}