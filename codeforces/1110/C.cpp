#include "bits/stdc++.h"
using namespace std;
int query(int x) {
	int first = 31;
	for(int i = 31; i >= 0; i--) {
		if((x >> i) & 1) {
			first = i;
			break;
		}
	}
	int prev = x;
	for(int i = first; i >= 0; i--) {
		if(((x >> i) & 1) == 0) {
			x |= 1 << i;
		} 
	}
	if(x != prev) return x;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return x / i;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", query(x));
	}
	return 0;
}