#include "bits/stdc++.h"
using namespace std;
int a[1111], b[1111];

int main(int argc, char const *argv[])
{
	int n, s;
	scanf("%d %d", &n, &s);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	if(a[1] == 0) {
		puts("NO");
		exit(0);
	}
	if(a[s] == 1) {
		puts("YES");
		exit(0);
	}
	if(b[s] == 0) {
		puts("NO");
		exit(0);
	}
	for(int i = s + 1; i <= n; i++) {
		if(a[i] == 1 && b[i] == 1) {
			puts("YES");
			exit(0);
		}
 	}
 	puts("NO");
	return 0;
}