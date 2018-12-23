#include "bits/stdc++.h"
using namespace std;
int a[3][2];
typedef pair <int, int> pii;

set <pii> ss;
void go(int p, int q, int x, int y) {
	for(int i = min(p, x); i <= max(p, x); i++) {
		ss.insert(pii(i, q));
	}
	for(int i = min(q, y); i <= max(q, y); i++) {
		ss.insert(pii(x, i));
	}
}

int main(int argc, char const *argv[])
{
	set <int> s;
	for(int i = 0; i < 3; i++) {
		cin >> a[i][0] >> a[i][1];
		s.insert(a[i][0]);
		s.insert(a[i][1]);
	}	
	int ans = 1000000000;
	int optx = 0;
	int opty = 0;;
	for(auto i : s) {
		for(auto j : s) {
			int dist = 0;
			for(int x = 0; x < 3; x++) {
				dist += abs(i - a[x][0]) + abs(j - a[x][1]);
			}
			ans = min(ans, dist);
			if(ans == dist) {
				optx = i;
				opty = j;
			}
		}
	}
	for(int i = 0; i < 3; i++) {
		go(a[i][0], a[i][1], optx, opty);
	}
	cout << ss.size() << endl;
	for(auto i : ss) {	
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}