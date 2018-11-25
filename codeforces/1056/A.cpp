#include "bits/stdc++.h"
using namespace std;
int a[111];

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int r;
		cin >> r;
		while(r--) {
			int x;
			cin >> x;
			a[x] += 1;
		} 
	}
	for(int i = 1; i <= 100; i++) {
		if(a[i] == n) {
			cout << i << ' ';
		}
	}
	cout << endl;
	return 0;
}