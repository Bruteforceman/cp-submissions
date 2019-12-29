#include "bits/stdc++.h"
using namespace std;
vector <int> v[2][2];
int x[1005], y[1005];
int n;
 
void print(vector <int> v) {
	cout << v.size() << endl;
	for(auto i : v) cout << i << ' ';
	cout << endl;
}
 
int div2(int p) {
	int sign = p < 0 ? -1 : 1;
	p = abs(p);
	p /= 2;
	return sign * p;
}
long long dist(int i, int j) {
	long long dx = x[i] - x[j];
	long long dy = y[i] - y[j];
	return dx * dx + dy * dy;
}
 
void solve() {
	for(int i = 0; i <= 1; i++) {
		for(int j = 0; j <= 1; j++) {
			v[i][j].clear();
		}
	}
	for(int i = 1; i <= n; i++) {
		int p = x[i];
		int q = y[i];
		p %= 2;
		q %= 2;
		if(p < 0) p += 2;
		if(q < 0) q += 2;
		v[p][q].push_back(i);
	}
	int A = v[0][0].size() + v[1][1].size();
	if(1 <= A && A < n) {
		cout << A << endl;
		for(auto i : v[0][0]) cout << i << ' ';
		for(auto i : v[1][1]) cout << i << ' ';
		cout << endl;
		exit(0);
	} 
	if(A == 0) {
		int B = v[0][1].size();
		if(1 <= B && B < n) {
			print(v[0][1]);
			exit(0);
		}
	} else {
		int B = v[0][0].size();
		if(1 <= B && B < n) {
			print(v[0][0]);
			exit(0);
		}
	}
	for(int i = 1; i <= n; i++) {
		x[i] = div2(x[i]);
		y[i] = div2(y[i]);
	}
	solve();
}
void solve_small() {
	for(int i = 1; i < (1 << n) - 1; i++) {
		vector <int> p, q;
		for(int j = 0; j < n; j++) {
			if((i >> j) & 1) {
				p.push_back(j + 1);
			} else q.push_back(j + 1);
		}
		set <long long> s;
		for(int j : p) {
			for(int k : p) {
				if(j != k) {
					s.insert(dist(j, k));
				}
			}
		}
		for(int j : q) {
			for(int k : q) {
				if(j != k) {
					s.insert(dist(j, k));
				}
			}
		}
		bool good = true;
		for(int j : p) {
			for(int k : q) {
				if(s.find(dist(j, k)) != s.end()) {
					good = false;
				}
			}
		}
		if(good) {
			print(p);
			exit(0);
		}
	}
}
 
int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		x[i] += 2000000;
		y[i] += 2000000;
	}
	if(n <= 10) {
		solve_small();
	} else {
		solve();
	}
	return 0;
}