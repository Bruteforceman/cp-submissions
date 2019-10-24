/**
 *    author:  tourist
 *    created: 27.05.2018 19:00:11       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
const int md = 998244353;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
 
inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (int) ((long long) a * b % md);
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (md)
  );
  return m;
}
 
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
 
inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
 
namespace ntt {
  int base = 1;
  vector<int> roots = {0, 1};
  vector<int> rev = {0, 1};
  int max_base = -1;
  int root = -1;
 
  void init() {
    int tmp = md - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      max_base++;
    }
    root = 2;
    while (true) {
      if (power(root, 1 << max_base) == 1) {
        if (power(root, 1 << (max_base - 1)) != 1) {
          break;
        }
      }
      root++;
    }
  }
 
  void ensure_base(int nbase) {
    if (max_base == -1) {
      init();
    }
    if (nbase <= base) {
      return;
    }
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      int z = power(root, 1 << (max_base - 1 - base));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = mul(roots[i], z);
      }
      base++;
    }
  }
 
  void fft(vector<int> &a) {
    int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          int x = a[i + j];
          int y = mul(a[i + j + k], roots[j + k]);
          a[i + j] = x + y - md;
          if (a[i + j] < 0) a[i + j] += md;
          a[i + j + k] = x - y + md;
          if (a[i + j + k] >= md) a[i + j + k] -= md;
        }
      }
    }
  }
 
  vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
    int need = (int) (a.size() + b.size() - 1);
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq) b = a; else fft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; i++) {
      a[i] = mul(mul(a[i], b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
  }
 
  vector<int> square(vector<int> a) {
    return multiply(a, a, 1);
  }
}

long long ans[12 * 100010];

int n, k;
int cnt[300010];

long long fac[300010];
long long invf[300010];
long long nCr(int n, int r) {
	if(n < r) return 0;
	long long num = fac[n];
	long long den = (invf[n - r] * invf[r]) % md;
	return (num * den) % md;
}

void solve(int red) {
	int one = 0, two = 0;
	for(int i = 1; i < red; i++) {
		if(cnt[i] == 1) {
			one += 1;
		} else if (cnt[i] > 1) {
			two += 1;
		}
	}
	vector <int> p (one + 1);
	vector <int> q (two * 2 + 1);
	for(int i = 0; i <= one; i++) {
		p[i] = mul(power(2, i), nCr(one, i));
	}
	for(int i = 0; i <= two * 2; i++) {
		q[i] = nCr(2 * two, i);
	} 
	// for(auto i : p) cout << i << ' ';
	// cout << endl;
	// for(auto i : q) cout << i << ' ';
	// cout << endl; 

	vector <int> v = ntt::multiply(p, q);
	for(int i = 0; i < v.size(); i++) {
		ans[i * 2 + red * 2 + 2] += v[i];
		ans[i * 2 + red * 2 + 2] %= md;
	}
}

int main() {
	scanf("%d %d", &n, &k);

	fac[0] = 1;
	invf[0] = 1;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x] += 1;
		fac[i] = mul(fac[i - 1], i);
		invf[i] = inv(fac[i]);
	}
	for(int i = 1; i <= k; i++) {
		int red;
		scanf("%d", &red);
		solve(red);
	}
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int x;
		scanf("%d", &x);
		printf("%lld\n", ans[x]);
	}
	return 0;
}