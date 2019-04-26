#include "bits/stdc++.h"
using namespace std;
int a[200010];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector <int> l, r;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int last = -1;
	string ans = "";
	int x = 1, y = n;
	while(x <= y) {
		if(a[x] < a[y]) {
			if(last < a[x]) {
				ans += "L";
				last = a[x];
				++x;
			} else if (last < a[y]) {
				ans += "R";
				last = a[y];
				--y;
			} else break;
		} else {
			if(last < a[y]) {
				ans += "R";
				last = a[y];
				--y;
			} else if (last < a[x]) {
				ans += "L";
				last = a[x];
				++x;
			} else break;
		}
	}
	printf("%d\n", (int)ans.size());
	printf("%s\n", ans.c_str());
	return 0;
}