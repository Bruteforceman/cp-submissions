#include "bits/stdc++.h"
using namespace std;
int a[1111];
long long p[1111];
int x[1111];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	vector <int> v;
	for(int k = 1; k <= n; k++) {
		bool bad = false;
		for(int i = 0; i < k; i++) {
			x[i] = a[i+1] - a[i];
		}
		for(int i = 1; i <= n; i++) {
			p[i] = p[i - 1] + x[(i - 1) % k];
		}
		for(int i = 1; i <= n; i++) {
			if(a[i] != p[i]) {
				bad = true;
			}
		}
		if(!bad) {
			v.push_back(k);
		}
	}
	printf("%u\n", v.size());
	for(auto i : v) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}