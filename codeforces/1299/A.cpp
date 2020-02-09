#include "bits/stdc++.h"
using namespace std;
int cnt[40];
int a[100010];
const int logn = 32;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for(int j = 0; j < logn; j++) {
			cnt[j] += ((a[i] >> j) & 1);
		}
	}
	int opt = 0;
	int id = 1;
	for(int i = 1; i <= n; i++) {
		int num = 0;
		for(int j = 0; j < logn; j++) {
			cnt[j] -= ((a[i] >> j) & 1);
			if(cnt[j] > 0) {
				num ^= 1 << j;
			}
		}
		if(opt < ((a[i] | num) - num)) {
			opt = (a[i] | num) - num;
			id = i;
		}
		for(int j = 0; j < logn; j++) {
			cnt[j] += ((a[i] >> j) & 1);
		}
	}
	printf("%d ", a[id]);
	for(int i = 1; i <= n; i++) {
		if(i != id) printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}