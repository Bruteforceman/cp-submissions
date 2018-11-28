#include "bits/stdc++.h"
using namespace std;
int s[100010], r[100010];
vector <int> v[100010];
long long val[100010];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &s[i], &r[i]);
		v[s[i]].push_back(r[i]);
	}
	for(int i = 1; i <= m; i++) {
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
	}
	long long res = 0;
	long long ans = 0;
	set <int> can;
	for(int i = 1; i <= m; i++) {
		can.insert(i);
	}
	for(int i = 1; i <= n; i++) {
		vector <int> del;
		for(auto j : can) {
			if(v[j].size() < i) {
				del.push_back(j);
			} else {
				ans += v[j][i - 1];
				val[j] += v[j][i - 1];
				if(val[j] < 0) {
					del.push_back(j);
				} 
			}
		}
		for(auto j : del) {
			ans -= val[j];
			can.erase(j);
		}
		res = max(res, ans);
	}
	printf("%lld\n", res);
	return 0;
}