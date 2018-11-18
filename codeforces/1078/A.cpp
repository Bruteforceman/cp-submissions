#include "bits/stdc++.h"
using namespace std;

struct point {
	double x, y;
	point () {}
	point (double x, double y) : x(x), y(y) {}
	void in () {
		cin >> x >> y;
	}
};

double man(point a, point b) {
	return fabs(a.x - b.x) + fabs(a.y - b.y);
}
double dist(point a, point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

point a, b;
double A, B, C;

point getP(point p, int is_x) {
	if(is_x) {
		return point(p.x, (-A * p.x - C) / B);
	} else {
		return point((-B * p.y - C) / A, p.y);
	}
}

int main(int argc, char const *argv[])
{
	long long aa, bb, cc;
	cin >> aa >> bb >> cc;
	A = aa;
	B = bb;
	C = cc;

	a.in(); 
	b.in();
	double ans = man(a, b);
	for(int i = 0; i <= 1; i++) {
		for(int j = 0; j <= 1; j++) {
			if(bb == 0) {
				if(i == 1 || j == 1) continue;
			}
			if(aa == 0) {
				if(i == 0 || j == 0) continue;
			}
			point p = getP(a, i);
			point q = getP(b, j);
			ans = min(ans, man(a, p) + dist(p, q) + dist(q, b));
		}
	}
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}