#include "bits/stdc++.h"
using namespace std;
char s[100010];

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	vector <vector <int>> answer;
	int upper = 0;
	while(true) {
		vector <int> can;
		for(int i = 1; i < n; i++) {
			if(s[i] == 'R' && s[i + 1] == 'L') {
				can.push_back(i);
			} 
		}
		if(can.empty()) break;
		answer.push_back(can);
		upper += can.size();
		for(auto i : can) {
			swap(s[i], s[i + 1]);
		}
	}
	if(answer.size() <= k && k <= upper) {
		int cnt = answer.size();
		vector <int> last;
		while(cnt < k) {
			last.push_back(answer.back().back());
			answer.back().pop_back();
			if(answer.back().empty()) {
				answer.pop_back();
			} else ++cnt;
		}
		for(auto i : answer) {
			printf("%d", (int) i.size());
			for(auto j : i) {
				printf(" %d", j);
			}
			printf("\n");
		}
		reverse(last.begin(), last.end());
		for(auto i : last) {
			printf("1 %d\n", i);
		}
	} else {
		printf("-1\n");
	}
	return 0;
}