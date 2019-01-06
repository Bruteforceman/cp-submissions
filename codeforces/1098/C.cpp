#include "bits/stdc++.h"
using namespace std;
int n;
long long s;
int par[100010];

long long ceiling(long long p, long long q) {
	return (p + q - 1) / q;
}

long long opt(int k) {
	long long cur = 1;
	int dep = 1;
	int tot = 0;
	long long ans = 0;
	while(tot + cur <= n) {
		tot += cur;
		ans += 1LL * dep * cur;
		dep += 1;
		cur *= k;
	}
	ans += 1LL * (n - tot) * dep;
	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%d %lld", &n, &s);
	if(s > opt(1)) {
		printf("No\n");
		exit(0);
	}
	int k = -1;
	for(int i = 1; i <= n; i++) {
		if(opt(i) <= s) {
			k = i;
			break;
		}
	} 
	if(k == -1) {
		printf("No\n");
		exit(0);
	}


	long long cur = 1;
	int dep = 1;
	int tot = 0;
	vector <int> ans;

	while(tot + cur <= n) {
		ans.push_back(cur);
		tot += cur;
		s -= 1LL * dep * cur;
		dep += 1;
		cur *= k;
	}
	if(tot < n) {
		ans.push_back(n - tot);
		s -= 1LL * (n - tot) * dep;
		dep += 1;
	}
	for(int i = ans.size() - 1; i >= 0; i--) {
		while(s > 0 && ans[i] > 1) {
			long long id = min((long long) ans.size(), s + i);
			s -= id - i;
			if(id >= ans.size()) {
				ans.push_back(1);
			} else {
				ans[id] += 1;
			}
			--ans[i];
		}
	}	

	int now = 1;
	vector <int> lv;
	lv.push_back(1);

	for(int i = 1; i < ans.size(); i++) {
		vector <int> nlv;
		for(int j = 0; j < ans[i]; j++) {
			par[++now] = lv[j / k];
			nlv.push_back(now);
		}
		lv = nlv;
	}

	printf("Yes\n");
	for(int i = 2; i <= n; i++) {
		printf("%d ", par[i]);
	}
	printf("\n");
	return 0;	
}