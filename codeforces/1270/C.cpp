#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		long long sum = 0;
		long long xsum = 0;
		for(int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			sum += x;
			xsum ^= (2LL * x);
		}
		vector <long long> v;
		long long extra = (1LL << 52);
		if(sum % 2 == 1) {
			extra += 1;
		}
		sum += extra;
		xsum ^= (2LL * extra);
		long long diff = xsum - sum;
		printf("3\n");
		printf("%lld %lld %lld\n", extra, diff / 2, diff / 2);
	}
	return 0;
}