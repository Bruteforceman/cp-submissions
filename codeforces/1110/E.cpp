#include "bits/stdc++.h"
using namespace std;
int a[100010], b[100010];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	if(a[1] != b[1] || a[n] != b[n]) {
		printf("No\n");
		exit(0);
	}
	vector <int> u, v;
	for(int i = 2; i <= n; i++) {
		u.emplace_back(a[i] - a[i-1]);
		v.emplace_back(b[i] - b[i-1]);
	}
	sort(u.begin(), u.end());
	sort(v.begin(), v.end());
	for(int i = 0; i < u.size(); i++) {
		if(u[i] != v[i]) {
			printf("No\n");
			exit(0);
		}
	}
	printf("Yes\n");
	return 0;
}