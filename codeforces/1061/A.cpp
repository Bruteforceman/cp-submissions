#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	long long n, S;
	cin >> n >> S;
	long long take = S / n;	
	S -= take * n;
	if(S) {
		cout << (take + 1) << endl;
	} else {
		cout << take << endl;
	}
	return 0;
}