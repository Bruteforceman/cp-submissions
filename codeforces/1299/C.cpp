#include "bits/stdc++.h"
using namespace std;
double a[1000010];
struct data {
	double first, avg;
	int second;
	data (double first, int second, double avg) : first(first), second(second), avg(avg) {}
	data () {} 
};
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	vector <data> v;
	for(int i = n; i >= 1; i--) {
		double opt = a[i];
		double sum = a[i];
		int id = i;
		while(!v.empty()) {
			sum += v.back().first;
			if(opt >= (sum / (v.back().second - i + 1))) {
				opt = (sum / (v.back().second - i + 1));
				id = v.back().second;
				v.pop_back();
			} else {
				sum -= v.back().first;
				break;
			}
		}
		v.push_back(data(sum, id, opt));
	}

	for(int i = 1; i <= n; i++) {
		while(!v.empty() && v.back().second < i) {
			v.pop_back();
		}
		printf("%.10lf\n", v.back().avg);
	} 
	return 0;
}