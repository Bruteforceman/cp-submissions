#include "bits/stdc++.h"
using namespace std;
int l[111], r[111];
int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	cout << 2*n + 1 + (n - 1) + min(k - 1, n - k) << endl;
	return 0;
}