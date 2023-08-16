#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 10000;

int T, n, ans[N];
map<pii, int> m;
vi dx = {-1, -1, 0, 1, 1, 0}, dy = {0, -1, -1, 0, 1, 1};

void print_m(int d) {
	rep(x, -d, d+1) {
		rep(y, -d, d+1) printf("%3d", m[{x,y}]);
		printf("\n");
	}
}

int main() {
	// pre_processing
	int dir = 0;
	int ndir = 1;
	int x = 0, y = 0;
	vector<pii> cnt = {{1,1}, {0,2}, {0,3}, {0,4}, {0,5}};
	m[{x,y}] = 1;
	ans[0] = 1;
	rep(i, 1, N) {
		while (!m[{x+dx[ndir], y+dy[ndir]}] && i > 1)
			dir = ndir,
			ndir = (ndir+1)%6;
		x += dx[dir];
		y += dy[dir];
		set<int> neigh;
		rep(i, 0, 6) neigh.insert(m[{x+dx[i],y+dy[i]}]);
		sort(all(cnt));
		int idx = 0;
		while (neigh.count(cnt[idx].second))
			idx++;
		cnt[idx].first++;
		m[{x,y}] = cnt[idx].second;
		ans[i] = m[{x,y}];
	}
	// handle queries
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		printf("%d\n", ans[n-1]);
	}
}
