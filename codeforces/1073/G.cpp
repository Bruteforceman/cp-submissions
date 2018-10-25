#include "bits/stdc++.h"
using namespace std;
#define next adfdf
// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm
// Refer to "Suffix arrays: A new method for on-line txting searches",
// by Udi Manber and Gene Myers
 
//Usage:
// Fill txt with the characters of the txting.
// Call SuffixSort(n), where n is the length of the txting stored in txt.
// That's it!
 
//Output:
// SA = The suffix array. Contains the n suffixes of txt sorted in lexicographical order.
//       Each suffix is represented as a single integer (the SAition of txt where it starts).
// iSA = The inverse of the suffix array. iSA[i] = the index of the suffix txt[i..n)
//        in the SA array. (In other words, SA[i] = k <==> iSA[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix txt[i..n) is smaller
//        than txt[j..n) if and only if iSA[i] < iSA[j]
const int MAX = 200010;
char txt[MAX]; //input
int iSA[MAX], SA[MAX]; //output
int cnt[MAX], next[MAX]; //internal
bool bh[MAX], b2h[MAX];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return txt[a] < txt[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    SA[i] = i;
  }
  sort(SA, SA + n, smaller_first_char);
  //{SA contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || txt[SA[i]] != txt[SA[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of SA[i-1] == the first h characters of SA[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      next[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing txtings starting with the same h characters}
 
    for (int i = 0; i < n; i = next[i]){
      cnt[i] = 0;
      for (int j = i; j < next[i]; ++j){
        iSA[SA[j]] = i;
      }
    }
 
    cnt[iSA[n - h]]++;
    b2h[iSA[n - h]] = true;
    for (int i = 0; i < n; i = next[i]){
      for (int j = i; j < next[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0){
          int head = iSA[s];
          iSA[s] = head + cnt[head]++;
          b2h[iSA[s]] = true;
        }
      }
      for (int j = i; j < next[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0 && b2h[iSA[s]]){
          for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      SA[iSA[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    iSA[SA[i]] = i;
  }
}
// End of suffix array algorithm
 
 
// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
int lcp[MAX];
// lcp[i] = length of the longest common prefix of suffix SA[i] and suffix SA[i-1]
// lcp[0] = 0
void getlcp(int n)
{
  for (int i=0; i<n; ++i) 
    iSA[SA[i]] = i;

  lcp[0] = 0;

  for (int i=0, h=0; i<n; ++i)
  {
    if (iSA[i] > 0)
    {
      int j = SA[iSA[i]-1];
      while (i + h < n && j + h < n && txt[i+h] == txt[j+h]) 
          h++;
      lcp[iSA[i]] = h;

      if (h > 0) 
        h--;
    }
  }
}
// End of longest common prefixes algorithm

const int logn = 17;
int dp[18][200010];
int logx[200010];
int pos[200010];
int a[200010], b[200010];
int n;
const int magic = 450;
bool cmp(int p, int q) {
	return lcp[p] < lcp[q];
}
int LCP(int p, int q) {
	if(p == q) return n - p;
	p = pos[p];
	q = pos[q];
	if(p > q) swap(p, q);
	p += 1;
	int b = logx[q - p + 1];
	return lcp[min(dp[b][p], dp[b][q - (1 << b) + 1], cmp)];
}
int rmq(int p, int q) {
	int b = logx[q - p + 1];
	return min(dp[b][p], dp[b][q - (1 << b) + 1], cmp);
}

int l[200010], r[200010];
int lft[200010], ryt[200010];
int Pa[200010], Pb[200010];

inline int build(int b, int e) {
	if(b > e) return -1;
	int idx = rmq(b, e);
	l[idx] = b;
	r[idx] = e;
	lft[idx] = build(b, idx - 1);
	ryt[idx] = build(idx + 1, e);
	return idx;
}

inline int calcA(int i, int j) {
	i = max(0, i);
	return i == 0 ? Pa[j] : Pa[j] - Pa[i-1];
} 
inline int calcB(int i, int j) {
	i = max(0, i);
	return i == 0 ? Pb[j] : Pb[j] - Pb[i-1];
}
// 6 4 0 2 5 1 3
// 0 1 3 1 0 2 0 
int main()
{
	int Q;
	scanf("%d %d", &n, &Q);
	scanf("%s", txt);
	suffixSort(n);
	getlcp(n);
	for(int i = 0; i < n; i++) {
		dp[0][i] = i;
		pos[SA[i]] = i;
	}
	logx[1] = 0;
	for(int i = 2; i <= n; i++) {
		logx[i] = logx[i >> 1] + 1;
	}
	for(int i = 1; i <= logn; i++) {
		for(int j = 0; j < n; j++) {
			int shift = (1 << (i-1));
			if(j + shift < n) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + shift], cmp);
			}
		}
	}
	int root = build(0, n-1);
	while(Q--) {
		int p, q;
		scanf("%d %d", &p, &q);
		for(int i = 0; i < p; i++) {
			scanf("%d", &a[i]);
			--a[i];
		}
		for(int i = 0; i < q; i++) {
			scanf("%d", &b[i]);
			--b[i];
		}
		long long ans = 0;
		if(p <= magic || q <= magic) {
			for(int i = 0; i < p; i++) {
				for(int j = 0; j < q; j++) {
					ans += LCP(a[i], b[j]);
				}
			}
		} else {
			for(int i = 0; i < n; i++) {
				Pa[i] = Pb[i] = 0;
			}
			for(int i = 0; i < p; i++) {
				Pa[pos[a[i]]] += 1;
			}
			for(int i = 0; i < q; i++) {
				Pb[pos[b[i]]] += 1;
			}
			for(int i = 1; i < n; i++) {
				Pa[i] += Pa[i - 1];
				Pb[i] += Pb[i - 1];
			}
			for(int now = 0; now < n; now++) {
				ans += 1LL * (n - SA[now]) * calcA(now, now) * calcB(now, now);
				ans += 1LL * lcp[now] * calcA(l[now] - 1, now - 1) * calcB(now, r[now]);
				ans += 1LL * lcp[now] * calcB(l[now] - 1, now - 1) * calcA(now, r[now]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}