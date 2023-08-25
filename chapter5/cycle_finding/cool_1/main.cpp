#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll N, x, y;
string sequence;
vi seq;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
vector<string> grid;
vector<vi> vis;

int main() {
	// Read input
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> sequence;
	for (char c : sequence)
		if (c == '^') seq.push_back(0);
		else if (c == '>') seq.push_back(1);
		else if (c == 'v') seq.push_back(2);
		else if (c == '<') seq.push_back(3);
	grid.assign(N, "");
	rep(i, 0, N) cin >> grid[i];
	rep(i, 0, N) rep(j, 0, N)
		if (grid[i][j] == 'R')
			x = i, y = j, grid[i][j] = '.';
	// Start algorithm
	// Find repeat square
	vis.assign(N, vi(N, 0));
	while (!vis[x][y]) {
		vis[x][y] = 1;
		for (ll d : seq)
			if (grid[x+dx[d]][y+dy[d]] == '.')
				x += dx[d],
				y += dy[d];
	}
	ll rep_x = x, rep_y = y;
	// Count length of trial until another repeat
	vis.assign(N, vi(N, 0));
	ll X = 0;
	do {
		for (ll d : seq)
			if (grid[x+dx[d]][y+dy[d]] == '.')
				x += dx[d],
				y += dy[d],
				vis[x][y]++,
				X++;
	} while (x != rep_x || y != rep_y);
	ll rounds = max(vis[x][y], 1ll);
	do {
		for (ll d : seq)
			if (grid[x+dx[d]][y+dy[d]] == '.')
				x += dx[d],
				y += dy[d],
				rounds = min(rounds, vis[x][y]);
	} while (x != rep_x || y != rep_y);
	X /= rounds;
	X = max(X, 1ll);
	printf("%lld\n", X);
}
