#include "bits/stdc++.h"
using namespace std;
#define move i_cant_even_define_move

typedef pair <int, int> pii;
int n, m;
vector <string> s, t;
vector <string> v;
vector <pii> move;

void operate(int x, int y) {
	move.push_back(make_pair(x+1, y+1));
	if(v[x][y] == 'L' && v[x + 1][y] == 'L') {
		v[x][y] = v[x][y + 1] = 'U';
		v[x + 1][y] = v[x + 1][y + 1] = 'D'; 
	} else {
		v[x][y] = v[x + 1][y] = 'L';
		v[x][y + 1] = v[x + 1][y + 1] = 'R'; 
	}
}
void dfsCol(int x, int y) {
	if(v[x][y + 1] == 'U') {
		operate(x, y);
		return ;
	}
	if(v[x + 1][y + 1] == 'L') {
		operate(x, y + 1);
		operate(x, y);
		return ;
	}
	dfsCol(x + 1, y + 1);
	operate(x, y + 1);
	operate(x, y);
}
void dfsRow(int x, int y) {
	if(v[x + 1][y] == 'L') {
		operate(x, y);
		return ;
	}
	if(v[x + 1][y + 1] == 'U') {
		operate(x + 1, y);
		operate(x, y);
		return ;
	}
	dfsRow(x + 1, y + 1);
	operate(x + 1, y);
	operate(x, y);
}

vector <pii> getMoves(vector <string> u) {
	move.clear();
	v = u;
	if(n % 2 == 0) {
		for(int j = 0; j < m; j++) {
			for(int i = 0; i < n; i += 2) {
				if(v[i][j] == 'L') {
					dfsRow(i, j);
				}
			}
		}
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j += 2) {
				if(v[i][j] == 'U') {
					dfsCol(i, j);
				}
			}
		}
	}
	return move;
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);
	cin >> n >> m;
	s.resize(n);
	t.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	vector <pii> conv = getMoves(s);
	vector <pii> rev = getMoves(t);
	reverse(rev.begin(), rev.end());

	cout << (conv.size() + rev.size()) << endl;
	for(auto i : conv) {
		cout << i.first << ' ' << i.second << endl;
	}
	for(auto i : rev) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}