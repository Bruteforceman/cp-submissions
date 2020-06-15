#include "bits/stdc++.h"
using namespace std;
 
long long ask(int t, int i, int j, int k) {
	cout << t << " " << i << " " << j << " " << k << endl;
	long long ans;
	cin >> ans;
	return ans;
}
 
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int piv = 2;
	for(int i = 3; i <= n; i++) {
		if(ask(2, 1, piv, i) == -1) {
			piv = i;
		}
	}
	vector <pair <long long, int>> v;
	for(int i = 2; i <= n; i++) {
		if(i == piv) continue;
		v.push_back(make_pair(ask(1, 1, piv, i), i));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
 
	int far = v[0].second;
	deque <int> Q;
	Q.push_back(far);
 
	for(int i = 1; i < v.size(); i++) {
		if(ask(2, 1, far, v[i].second) == -1) {
			Q.push_front(v[i].second);
		} else {
			Q.push_back(v[i].second);
		}
	}
	Q.push_front(piv);
	Q.push_front(1);
 
	cout << "0";
	for(auto i : Q) {
		cout << " " << i;
	}
	cout << endl;
	return 0;
}