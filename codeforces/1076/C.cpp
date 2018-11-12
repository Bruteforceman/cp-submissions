#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	int t;
	cin >> t;
	cout.precision(10);
	cout << fixed;
	while(t--) {
		int d;
		cin >> d;
		if(d*d >= 4*d) {
			double a = (d + sqrt(d*d - 4*d)) / 2;
			double b = (d - sqrt(d*d - 4*d)) / 2;
			cout << "Y " << a << " " << b << '\n';
		} else {
			cout << "N\n"; 
		}
	}
	return 0;
}