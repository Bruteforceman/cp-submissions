#include "bits/stdc++.h"
using namespace std;
long long val[300010], mask[300010];
bool vis[300010];
long long st[300010];
const int bit = 63;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld", &val[i], &mask[i]);
		st[i] = val[i];
	}

	long long rem = (1LL << 62) - 1;
	long long ans = 0;

	while(true) {
		int idx = -1;
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				if(idx == -1 || __builtin_popcountll(mask[i] & rem) < __builtin_popcountll(mask[idx] & rem)) {
					idx = i;
				}
			}
		}
		if(idx == -1) break;

		long long value = 0;
		long long sum = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			if((mask[i] & rem) == (mask[idx] & rem)) {
				value += val[i];
				vis[i] = true;
			}
			sum += val[i];
		}
		if(sum > 0) {
			if(value > 0) {
				long long var = mask[idx] & rem;
				int bitpos = 0;
				for(int i = 0; i < bit; i++) {
					if((var >> i) & 1) {
						bitpos = i;
						break;
					}
				}
				long long rem_sum = 0;
				for(int i = 1; i <= n; i++) {
					if(vis[i]) continue;
					long long num = mask[i] & rem;
					if((num >> bitpos) & 1) {
						val[i] *= -1;
					}
					rem_sum += val[i];
				}
				ans |= 1LL << bitpos;
				if(rem_sum <= 0) break;
			}
		} else {
			if(value < 0) {
				long long var = mask[idx] & rem;
				int bitpos = 0;
				for(int i = 0; i < bit; i++) {
					if((var >> i) & 1) {
						bitpos = i;
						break;
					}
				}
				long long rem_sum = 0;
				for(int i = 1; i <= n; i++) {
					if(vis[i]) continue;
					long long num = mask[i] & rem;
					if((num >> bitpos) & 1) {
						val[i] *= -1;
					}
					rem_sum += val[i];
				}
				ans |= 1LL << bitpos;
				if(rem_sum >= 0) break;	
			}
		}
		rem ^= (mask[idx] & rem);
	}
	printf("%lld\n", ans);
	// long long total = 0;
	// for(int i = 1; i <= n; i++) {
	// 	if(__builtin_popcountll(mask[i] & ans) & 1) {
	// 		total -= st[i];
	// 	} else {
	// 		total += st[i];
	// 	}
	// }
	// printf("%lld\n", total);
	return 0;
}