#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, b, c, r;
		scanf("%d %d %d %d", &a, &b, &c, &r);
		if(a > b) swap(a, b);
		int p = c - r;
		int q = c + r;
		if(b <= p || q <= a) {
			printf("%d\n", abs(a - b));
		} else {
			printf("%d\n", max(0, p - a) + max(0, b - q));
		}
	}
	return 0;
}