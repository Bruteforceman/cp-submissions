#include "bits/stdc++.h"
using namespace std;
int l[100010], r[100010];
int u[100010], d[100010];
int suf[100010];
bool mark[100010];
int n;
const int inf = 1e9 + 7;


bool solve(vector <int> &rs, vector <int> &ds) {
	int sz = rs.size();
	if(sz == 1) return true; 
	suf[sz] = inf;
	for(int i = sz - 1; i >= 0; i--) {
		suf[i] = min(suf[i + 1], l[rs[i]]); 
	}
	for(int i = 0; i < sz - 1; i++) {
		if(r[rs[i]] <= suf[i + 1]) {
			for(int j = 0; j <= n; j++) {
				mark[j] = false;
			}
			vector <int> p, q;
			vector <int> x, y;
			for(int j = 0; j <= i; j++) {
				mark[rs[j]] = true;
			}
			for(int j : rs) {
				if(mark[j]) {
					p.push_back(j);
				} else {
					q.push_back(j);
				}
			}
			for(int j : ds) {
				if(mark[j]) {
					x.push_back(j);
				} else {
					y.push_back(j);
				}
			}
			rs.clear();
			ds.clear();
			return solve(p, x) && solve(q, y);
		}
	}
	suf[sz] = inf;
	for(int i = sz - 1; i >= 0; i--) {
		suf[i] = min(suf[i + 1], u[ds[i]]); 
	}
	for(int i = 0; i < sz - 1; i++) {
		if(d[ds[i]] <= suf[i + 1]) {
			for(int j = 0; j <= n; j++) {
				mark[j] = false;
			}
			vector <int> p, q;
			vector <int> x, y;
			for(int j = 0; j <= i; j++) {
				mark[ds[j]] = true;
			}
			for(int j : rs) {
				if(mark[j]) {
					p.push_back(j);
				} else {
					q.push_back(j);
				}
			}
			for(int j : ds) {
				if(mark[j]) {
					x.push_back(j);
				} else {
					y.push_back(j);
				}
			}
			rs.clear();
			ds.clear();
			return solve(p, x) && solve(q, y);
		}
	}
	return false;
}

bool cmp1(int i, int j) {
	return r[i] < r[j];
}
bool cmp2(int i, int j) {
	return d[i] < d[j];
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	
	vector <int> rs, ds;
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", l + i, u + i, r + i, d + i);
		rs.push_back(i);
		ds.push_back(i);
	}
	sort(rs.begin(), rs.end(), cmp1);
	sort(ds.begin(), ds.end(), cmp2);

	if(solve(rs, ds)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}