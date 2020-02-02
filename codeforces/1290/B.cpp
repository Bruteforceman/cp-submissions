#include "bits/stdc++.h"
using namespace std;
int nxt[26][200010];
char txt[200010];

int main(int argc, char const *argv[])
{
	scanf("%s", txt);
	int n = strlen(txt);
	for(int j = 0; j < 26; j++) {
		nxt[j][n] = n;
	}
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) {
			nxt[j][i] = nxt[j][i + 1];
		}
		nxt[txt[i] - 'a'][i] = i;
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		--l; --r;
		int cnt = 0;
		for(int i = 0; i < 26; i++) {
			if(nxt[i][l] <= r) {
				++cnt;
			}
		}
		if(l == r) printf("Yes\n");
		else if (cnt <= 2) {
			if(txt[l] == txt[r]) printf("No\n");
			else printf("Yes\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}