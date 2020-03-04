#include "bits/stdc++.h"
using namespace std;
using pii = pair <int, int>;
pii a[1005][1005];
int n, m;
bool done[1005][1005];
char ans[1005][1005];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const char dir[] = {'R', 'L', 'D', 'U'};
const char rdir[] = {'L', 'R', 'U', 'D'};

bool inside(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}

void flood(int sx, int sy) {
	queue <pii> Q;
	Q.emplace(sx, sy);
	done[sx][sy] = true;
	ans[sx][sy] = 'X';
	while(!Q.empty()) {
		pii p = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++) {
			int x = p.first + dx[i];
			int y = p.second + dy[i];
			if(inside(x, y) && !done[x][y] && pii(sx, sy) == a[x][y]) {
				done[x][y] = true;
				Q.emplace(x, y);
				ans[x][y] = rdir[i];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	m = n;
	vector <pii> block;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d %d", &a[i][j].first, &a[i][j].second);
			if(a[i][j] != pii(-1, -1)) {
				--a[i][j].first;
				--a[i][j].second;
				if(pii(i, j) == a[i][j]) {
					block.emplace_back(i, j);
				}
			}
		}
	} 
	for(auto i : block) {
		flood(i.first, i.second);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(done[i][j]) {
				continue;
			}
			if(a[i][j] != pii(-1, -1)) {
				printf("INVALID\n");
				exit(0);
			}
			ans[i][j] = '*';
			for(int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if(inside(x, y) && !done[x][y]) {
					ans[i][j] = dir[k];
					break;
				}
			}
			if(ans[i][j] == '*') {
				printf("INVALID\n");
				exit(0);
			}
		}
	}
	printf("VALID\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}