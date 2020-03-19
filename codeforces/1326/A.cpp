#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		if(n == 1) {
			puts("-1");
		} else {
			for(int i = 1; i < n; i++) printf("5");
			printf("8\n");
		}
	}
	return 0;
}