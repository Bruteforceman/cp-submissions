#include "bits/stdc++.h"
using namespace std;
int n;
int a[300010];
int pos[300010];


typedef pair <int, int> pii;
vector <pii> v;

void Swap(int i, int j) {
	if(i == j) return ;
	v.push_back(pii(i, j));
	swap(a[i], a[j]);
	swap(pos[a[i]], pos[a[j]]);
}

void performSwap(int i, int j) {
	int l = (i <= n / 2) ? n : 1;
	int r = (j <= n / 2) ? n : 1;
	if(abs(i - j) >= (n / 2)) {
		Swap(i, j);
	} else if(l == r) {
		Swap(i, l);
		Swap(j, r);
		Swap(i, l);
	} else {
		Swap(i, l);
		Swap(j, r);
		Swap(l, r);
		Swap(i, l);
		Swap(j, r);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for(int i = 2; i < n; i++) {
		if(pos[i] != i) {
			performSwap(pos[i], i);
		}
	}
	if(a[1] != 1) {
		performSwap(1, n);
	}
	printf("%d\n", (int) v.size());
	for(auto i : v) {
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}