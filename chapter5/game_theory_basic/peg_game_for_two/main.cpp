#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAX = 1e9;

vector<vi> board(5, vi());
map<vector<vi>, ll> m;

void print_board() {
	rep(i, 0, 5) {
		rep(j, i, 4) printf("  ");
		for (ll x : board[i]) printf("%3lld ", x);
		printf("\n");
	}
	printf("\n");
}

// down left; down right; left; right; up left; up right
vi from_i = {-1, -1, 0, 0, 1, 1};
vi from_j = {0, -1, 1, -1, 1, 0};
vi to_i = {1, 1, 0, 0, -1, -1};
vi to_j = {0, 1, -1, 1, -1, 0};

ll calc() {
	if (m.count(board)) return m[board];
	ll res = -MAX;
	rep(i, 1, 5) rep(j, 0, sz(board[i])) {
		if (board[i][j] == 0) continue;
		rep(k, 0, sz(from_i)) {
			ll fi = i+from_i[k];
			ll ti = i+to_i[k];
			if (fi >= 5 || ti >= 5) continue;
			ll fj = j+from_j[k];
			ll tj = j+to_j[k];
			if (fj < 0 || tj < 0) continue;
			if (fj >= sz(board[fi]) || tj >= sz(board[ti])) continue;
			if (board[fi][fj] == 0 || board[ti][tj] != 0) continue;
			ll tmp = board[i][j];
			ll v = board[fi][fj]*tmp;
			board[ti][tj] = board[fi][fj];
			board[fi][fj] = board[i][j] = 0;
			//print_board();

			res = max(res, v - calc());

			board[fi][fj] = board[ti][tj];
			board[i][j] = tmp;
			board[ti][tj] = 0;
			//printf("Backtrack\n");
			//print_board();
		}
	}
	if (res == -MAX) return m[board] = 0;
	return m[board] = res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 0, 5) {
		board[i].assign(i+1, 0);
		rep(j, 0, i+1) cin >> board[i][j];
	}
	printf("%lld\n", calc());
}
