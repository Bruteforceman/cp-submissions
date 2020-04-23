#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
//
//
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define ll long long
#define ld long double
#define gap ' '
#define endl '\n'
 
void solve() {
	int n;
	cin>>n;
	vector<int>v(n),p(n);
	for(int &x:v)cin>>x;
	p[0]=v[0];
	for(int i=1;i<n;i++)
	p[i]=p[i-1]+v[i];
	if(p[n-1]%2 != 0) {
		cout<<0<<endl;
		return;
	}
	int s=p[n-1]/2;
	int ans=0;
	for(int i=0;i<n-1;i++)
	if(p[i]==s) ans++;
	
	cout<<ans<<endl;
}
void solve(bool testcase) {
	int t;cin>>t;while(t--)solve();
}
int32_t main() {
	fio
	solve();
	return 0;
}