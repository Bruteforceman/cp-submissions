#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	long long a, b, c;
	cin >> a >> b >> c;
	if(a == b) {
		cout << (a + b + c * 2) << endl; 
	} else {
		cout << 2LL * (c + min(a, b)) + 1 << endl;
	}
	return 0;
}