#include <bits/stdc++.h>
using namespace std;
long long val[100010];
typedef pair <int, int> pii;
long long xval[100010], sval[100010];

vector <pair <long long, long long>> solve(vector <pii> v) {
	vector <pii> event;
	int n = v.size();
	for(int i = 1; i <= n; i++) {
		int l = v[i - 1].first;
		int r = v[i - 1].second;
		event.push_back(pii(l, -i));
		event.push_back(pii(r, i));
	}
	sort(event.begin(), event.end());
	long long sum = 0;
	long long xsum = 0; 
	long long x_aux = 0;
	long long s_aux = 0;
	
	for(int i = 0; i < event.size(); i++) {
		int id = event[i].second;
		if(id < 0) {
			id = abs(id);
			s_aux += val[id];
			x_aux ^= val[id];
			sval[id] = sum - s_aux;
			xval[id] = xsum ^ x_aux;
			sum += val[id];
			xsum ^= val[id];
		} else {
			id = abs(id);
			sum -= val[id];
			xsum ^= val[id];
			sval[id] += s_aux;
			xval[id] ^= x_aux;
		}
	}
	vector <pair <long long, long long>> ans;
	for(int i = 1; i <= n; i++) {
		ans.push_back(make_pair(sval[i], xval[i]));
	}
	return ans;
} 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	scanf("%d", &n);
	vector <pii> u, v;
	for(int i = 1; i <= n; i++) {
		val[i] = rng();		
		int p, q, r, s;
		scanf("%d %d %d %d", &p, &q, &r, &s);
		u.push_back(pii(p, q));
		v.push_back(pii(r, s));
	}
	vector <pair <long long, long long>> A = solve(u);
	vector <pair <long long, long long>> B = solve(v);
	if(A == B) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}