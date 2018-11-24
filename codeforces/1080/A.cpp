#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	long long n, k;
	cin >> n >> k;
	cout << ((2*n + k - 1) / k) + ((5*n + k - 1) / k) + ((8*n + k - 1) / k) << endl;
	return 0;
}