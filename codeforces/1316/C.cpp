#include "bits/stdc++.h"
using namespace std;
int a[1000010];
int b[1000010];

int main(int argc, char const *argv[])
{
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);	
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", b + i);
	}
	int idxA = 0, idxB = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] % p == 0) {
			++idxA;
		} else break;
	}
	for(int i = 0; i < m; i++) {
		if(b[i] % p == 0) {
			++idxB;
		} else break;
	}
	printf("%d\n", idxA + idxB);
	return 0;
}