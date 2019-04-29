#include "bits/stdc++.h"
using namespace std;
int cnt[3];
int p[400010];
const int maxn = 400000;

int main(int argc, char const *argv[])
{
	for(int i = 2; i * i <= maxn; i++) {
		if(p[i] == 1) continue;
		for(int j = i * i; j <= maxn; j += i) {
			p[j] = 1;
		}
	}
	int n;
	scanf("%d", &n);
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x] += 1;
		sum += x;
	}
	vector <int> v;
	for(int i = 2; i <= sum; i++) {
		if(p[i] == 0) {
			v.emplace_back(i);
		}
	}
	int pt = 0;
	int cur = 0;
	while(pt < v.size()) {
		while(v[pt] - cur >= 2 && cnt[2] > 0) {
			printf("2 ");
			cur += 2;
			--cnt[2];
		}
		while(v[pt] - cur >= 1 && cnt[1] > 0) {
			printf("1 ");
			cur += 1;
			--cnt[1];
		}
		++pt;
	}
	while(cnt[2]--) {
		printf("2 ");
	}
	while(cnt[1]--) {
		printf("1 ");
	}
	printf("\n");
	return 0;
}