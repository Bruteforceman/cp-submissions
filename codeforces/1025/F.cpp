#include "bits/stdc++.h"
using namespace std;

struct point {
	long long x, y;
	point () {}
	point (long long x, long long y) : x(x), y(y) {}
	point operator + (point p) {
		return point(x + p.x, y + p.y);
	}
	point operator - (point p) {
		return point(x - p.x, y - p.y);
	}
	point operator * (long long c) {
		return point(x * c, y * c);
	} 
} a[2005], b[2005];
int pos[2005];

struct pii {
	point first;
	int second;
	int i, j;
	pii (point first, int second, int i, int j) : first(first), second(second), i(i), j(j) {}
	pii () {}
};

long long s;
int n;

long long cross(point p, point q) {
	return p.x * q.y - q.x * p.y;
}
long long dot(point p, point q) {
	return p.x * q.x + p.y * q.y;
}

bool height(point p, point q) {
	if(p.y == q.y) return p.x < q.x;
	return p.y < q.y;
}
bool cmp(pii p, pii q) {
	if(cross(p.first, q.first) == 0) {
		return p.second < q.second;
	}
	return cross(p.first, q.first) > 0;
}

int searchPos(int l, int r, point p, int i) {
	if(l == r) {
		return (cross(p, a[l] - b[i]) > 0) ? l : n;
	}
	int m = (l + r) >> 1;
	if(cross(p, a[m] - b[i]) <= 0) {
		return searchPos(m + 1, r, p, i);
	} else {
		return searchPos(l, m, p, i);
	}
}

long long nC2(int x) {
	return (x * (x - 1)) / 2;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i].x, &a[i].y);
	}
	sort(a, a + n, height);
	for(int i = 0; i < n; i++) {
		b[i] = a[i];
		pos[i] = i;
	}
	vector <pii> v;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			point p = a[i] - a[j];
			int x = i;
			int y = j;
			if(p.y < 0) {
				swap(x, y);
				p = p * -1;
			} else if (p.y == 0 && p.x < 0) {
				swap(x, y);
				p = p * -1;
			}
			v.push_back(pii(p, 0, x, y));
			v.push_back(pii(p, 1, x, y));
		}
	}
	sort(v.begin(), v.end(), cmp);
	
	long long ans = 0;
	for(auto i : v) {
		if(i.second == 1) {
			swap(a[pos[i.i]], a[pos[i.j]]);
			swap(pos[i.i], pos[i.j]);
		} else {
			// printf("Segment %lld %lld %lld %lld\n", b[i.i].x, b[i.i].y, b[i.j].x, b[i.j].y);
			// for(int g = 0; g < n; g++) {
			// 	printf("%lld %lld\n", a[g].x, a[g].y);
			// }
			// printf("\n");
			assert(cross(i.first, a[0] - b[i.i]) <= cross(i.first, a[n-1] - b[i.i]));
			int kp = n - searchPos(0, n-1, i.first, i.i);
			int kn = n - 2 - kp;
			ans += nC2(kp) * nC2(kn);
		}	
	}
	printf("%lld\n", ans);
	return 0;
}