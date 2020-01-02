#include "bits/stdc++.h"
using namespace std;
int a[1000010];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			a[i] = i - a[i];
		}
		int i = 1;
		int j = 1;
		do {
			i = a[i];
			j = a[a[j]];
		} while (i != j);
		int start = i;
		vector <int> v;
		do {
			v.push_back(i);
			i = a[i];
		} while(i != start);
		printf("%d\n", (int) v.size());
		for(auto i : v) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}