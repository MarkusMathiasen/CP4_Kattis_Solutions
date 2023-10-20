#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll N;
string goal = "ICPCASIASG";
vector<string> grid;
vi dx = {-2, -2, -1, 1, 2, 2, 1, -1};
vi dy = {-1, 1, 2, 2, 1, -1, -2, -2};

bool dfs(ll i, ll j, ll d) {
	if (i < 0 || i >= N || j < 0 || j >= N) return false;
	if (d == sz(goal)) return true;
	if (grid[i][j] != goal[d]) return false;
	rep(dir, 0, 8) if (dfs(i+dx[dir], j+dy[dir], d+1)) return true;
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	grid.assign(N, string(N, ' '));
	rep(i, 0, N) rep(j, 0, N) cin >> grid[i][j];
	rep(i, 0, N) rep(j, 0, N) if (dfs(i, j, 0)) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
}
