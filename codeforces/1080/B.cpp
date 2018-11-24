#include "bits/stdc++.h"
using namespace std;

long long sum(long long x) {
	if(x % 2 == 0) {
		return x / 2;
	} else {
		return -x + sum(x - 1);
	}
}

int main(int argc, char const *argv[])
{
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n", sum(r) - sum(l - 1));
	}
	return 0;
}