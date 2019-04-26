#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	long long x;
	cin >> x;
	set <int> s;
	while(true) {
		if(s.count(x)) break;
		s.insert(x);
		x += 1;
		while(x % 10 == 0) x /= 10;
	}
	cout << s.size() << endl;
	return 0;
}