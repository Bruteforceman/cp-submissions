#include "bits/stdc++.h"
using namespace std;
int x[100010];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, r;
		scanf("%d %d", &n, &r);
		set <int, greater<int> > s;
		for(int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			s.insert(x);
		}
		int move = 0;
		int cnt = 0;
		for(auto i : s) {
			if(i > move) {
				++cnt;
				move += r;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}