#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int n = s.size();

	map <char, int> cnt;
	for(int i = 0; i < n; i++) {
		cnt[s[i]] += 1;
	}
	for(auto i : cnt) {
		if(i.second >= n-1) {
			printf("Impossible\n");
			exit(0);
		}
	}
	for(int i = 0; i < n; i++) {
		string t = ""; 
		for(int j = 0; j < n; j++) {
			t += s[(i + j) % n];
		} 
		if(t == s) continue;
		bool bad = false;
		for(int j = 0; j < n; j++) {
			if(t[j] != t[n - j - 1]) {
				bad = true;
				break;
			}
		}
		if(!bad) {
			printf("1\n");
			exit(0);
		}
	}
	printf("2\n");
	return 0;
}