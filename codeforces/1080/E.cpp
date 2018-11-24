#include "bits/stdc++.h"
using namespace std;
typedef pair <long long, long long> pii;
int count(vector <pii> s) {
	int n = s.size();
	if(n == 0) return 0;
	vector<vector<int>> p(2,vector<int>(n,0));
	for(int z=0,l=0,r=0;z<2;z++,l=0,r=0) {
	    for(int i=0;i<n;i++)
	    {
	        if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
	        int L=i-p[z][i], R=i+p[z][i]-!z;
	        while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
	        if(R>r) l=L,r=R;
	    }
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		// cout << p[0][i] << ' ' << p[1][i] << endl;
		ans += p[0][i] + p[1][i] + 1;
	}
	return ans;
}
const int mod = 1000000000 + 7;
const int base = 129;
long long rand64() {
	long long ans = 0;
	for(int i = 0; i < 62; i++) {
		if(rand() & 1) {
			ans ^= 1LL << i; 
		}
	}
	return ans;
}
long long rand32() {
	long long ans = 0;
	for(int i = 0; i < 31; i++) {
		if(rand() & 1) {
			ans ^= 1LL << i; 
		}
	}
	return ans;
}

long long modpow(long long b, long long e) {
	if(e == 0) return 1;
	if(e & 1) {
		return (modpow(b, e - 1) * b) % mod;
	}
	long long m = modpow(b, e >> 1);
	return (m * m) % mod;
}
long long inverse(long long x) {
	return modpow(x, mod - 2);
}
 

long long H[252][252];
long long M[252][252];
long long S[252][252];
long long I[252][252];

char s[252][252];
long long mp[30];
long long np[30];
unordered_set <long long> good;
int n, m;

int solve(int x, int y) {
	int ans = 0;
	vector <pii> v;
	for(int i = 1; i <= n; i++) {
		long long prod = (M[i][y] * I[i][x - 1]) % mod;
		long long sum = (S[i][y] - S[i][x - 1]);
		long long xorsum = H[i][y] ^ H[i][x - 1];
		if(good.find(xorsum) == good.end()) {
			ans += count(v);
			v.clear();
		} else {
			v.emplace_back(prod, sum);
		}
	}
	ans += count(v);
	return ans;
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	for(int i = 0; i < 26; i++) {
		mp[i] = rand64();
		np[i] = rand32();
		good.insert(mp[i]);
	}
	good.insert(0);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	for(int i = 1; i <= n; i++) {
		M[i][0] = I[i][0] = 1;
		for(int x = 1; x <= m; x++) {
			S[i][x] = S[i][x - 1] + np[s[i][x] - 'a'];
			H[i][x] = H[i][x - 1] ^ mp[s[i][x] - 'a'];
			M[i][x] = M[i][x - 1] * np[s[i][x] - 'a'];
			M[i][x] %= mod;
			I[i][x] = inverse(M[i][x]);
		}
	}
	long long ans = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = i; j <= m; j++) {
			ans += solve(i, j);
		}
	}
	printf("%lld\n", ans);
	return 0;
}