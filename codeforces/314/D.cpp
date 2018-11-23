#include "bits/stdc++.h"
using namespace std;

// (a + ib) (p + iq) = (ap - bq) + (aq + pb)i
const long long inf = 1e15;
int x[100010], y[100010];
int n;
typedef pair <int, int> pii;
vector <pii> v;
bool del[100010];
bool out[2][100010];

bool good(long long g) {
	priority_queue <pii> P, N;
	for(int i = 1; i <= n; i++) {
		int c = y[i] + x[i];
		P.push(pii(c, i));
		N.push(pii(-c, i));
		del[i] = false;
		out[0][i] = out[1][i] = false;
	}
	int l = 0;
	for(int i = 0; i < n; i++) {
		int idx = v[i].second;
		del[idx] = true;
		while(l < i && v[l].first + g < v[i].first) {
			idx = v[l].second;
			del[idx] = false;
			if(out[0][idx]) {
				P.push(pii(y[idx] + x[idx], idx));
			}
			if(out[1][idx]) {
				N.push(pii(-y[idx] - x[idx], idx));
			}
			out[0][idx] = out[1][idx] = false;
			++l;
		}
		while(!P.empty() && del[P.top().second]) {
			out[0][P.top().second] = true;
			P.pop();
		}
		while(!N.empty() && del[N.top().second]) {
			out[1][N.top().second] = true;
			N.pop();
		}
		if(P.empty() || P.top().first <= (g - N.top().first)) {
			return true;
		}
	}
	return false;
}

long long search(long long b, long long e) {
	if(b == e) {
		return b;
	}
	long long m = (b + e) >> 1;
	if(good(m)) {
		return search(b, m);
	} else {
		return search(m + 1, e);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		x[i] = p;
		y[i] = q;
	}
	for(int i = 1; i <= n; i++) {
		int c = y[i] - x[i];
		v.push_back(pii(c, i));
	}
	sort(v.begin(), v.end());
	long long opt = search(0, 2000000000LL);
	printf("%.10lf\n", 0.5 * opt);
	return 0;
}