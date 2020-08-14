#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int get(int s) {
    return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
}

typedef complex<double> base;

void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(int i=0; i<n/2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}

	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> DOIT(vector<ll> &v, vector<ll> &w) {
	int n = 1;
	while(n < max(v.size(), w.size())) n <<= 1;
	n <<= 1;
	vector<base> v1(n), v2(n);
	vector<base> r1(n), r2(n);
	for(int i=0; i<v.size(); i++){
		v1[i] = base(v[i] >> 15, v[i] & 32767);
	}
	for(int i=0; i<w.size(); i++){
		v2[i] = base(w[i] >> 15, w[i] & 32767);
	}
	fft(v1, 0);
	fft(v2, 0);
	for(int i=0; i<n; i++){
		int j = (i ? (n - i) : i);
		base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
		base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
		base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
		base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
		r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
		r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
	}
	fft(r1, 1);
	fft(r2, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++){
		ll av = (ll)round(r1[i].real());
		ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
		ll cv = (ll)round(r2[i].imag());
		ret[i] = (av << 30) + (bv << 15) + cv;
	}
	while (ret.back() == 0) ret.pop_back();
	return ret;
}
const int maxn = 2e5 + 10;
const int maxval = 1e6;
long long cnt[maxval + 10];
int dp[maxval + 10];

int main(){
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  vector <ll> v (x + 1, 0);
  vector <ll> w (x + 1, 0);
  for(int i = 0; i <= n; i++) {
    int pos;
    scanf("%d", &pos);
    v[pos] += 1;
    w[x - pos] += 1;
  }
  vector <ll> mul = DOIT(v, w);
  mul.resize(2 * x + 1);
  for(int i = 1; i <= x; i++) {
    cnt[y + i] += mul[i + x];
  }
  memset(dp, -1, sizeof dp);
  for(int i = maxval; i >= 1; i--) {
    if(cnt[i]) {
      for(int j = i; j <= maxval; j += i) {
        dp[j] = max(dp[j], 2 * i);
      }
    }
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int l;
    scanf("%d", &l);
    printf("%d ", dp[l / 2]);
  }
  printf("\n");
}
