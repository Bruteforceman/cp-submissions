#include "bits/stdc++.h"
using namespace std;
int n;
int s[300010], t[300010];
int pos_s[300010]; 
int diff[300010];

vector <int> Si, Sj, D;

void update(int i, int j, int d) {
	if(d == 0) return ;
	Si.push_back(pos_s[i]);
	Sj.push_back(pos_s[j]);
	D.push_back(d);
	diff[i] -= d;
	diff[j] += d;
}
bool cmpS(int i, int j) {
	return s[i] < s[j];
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		pos_s[i] = i;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}
	sort(pos_s + 1, pos_s + n + 1, cmpS);
	sort(s + 1, s + n + 1);
	sort(t + 1, t + n + 1);
	// sort(pos_t + 1, pos_t + n + 1, cmpT);

	vector <int> pos, neg;
	for(int i = 1; i <= n; i++) {
		diff[i] = t[i] - s[i];
		if(s[i] == t[i]) continue;
		if(s[i] > t[i]) {
			neg.push_back(i);
		} else {
			pos.push_back(i);
		}
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += diff[i];
	}
	if(sum != 0) {
		printf("NO\n");
		exit(0);
	}
	int pt = 0;
	for(int i = 1; i <= n; i++) {
		if(diff[i] < 0) {
			printf("NO\n");
			exit(0);
		}
		while(pt < neg.size() && diff[i] > 0) {
			int id = neg[pt];
			if(diff[i] + diff[id] >= 0) {
				update(i, id, -diff[id]);
				++pt;
			} else {
				update(i, id, diff[i]);
			}
		}
		if(diff[i] != 0) {
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
	printf("%d\n", (int) D.size());
	for(int i = 0; i < D.size(); i++) {
		printf("%d %d %d\n", Si[i], Sj[i], D[i]);
	}
	return 0;
}