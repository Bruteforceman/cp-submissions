#include "bits/stdc++.h"
using namespace std;
char s[100010];
long long cnt[26][26];
long long tot[26];
void solve() {
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		for(int j = 0; j < 26; j++) {
			cnt[j][c] += tot[j];
		}
		tot[c] += 1;
	}
	long long mx = 0;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			mx = max(mx, cnt[i][j]);
		}
		mx = max(mx, tot[i]);
	}
	printf("%lld\n", mx);
}
int main(int argc, char const *argv[])
{
	solve();
 	return 0; 
}