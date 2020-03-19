#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int x = 0;
	for(int i = 1; i <= n; i++) {
		int b;
		scanf("%d", &b);
		int a = b + x;
		x = max(x, a);
		printf("%d ", a);
	}
	printf("\n");
	return 0;
}