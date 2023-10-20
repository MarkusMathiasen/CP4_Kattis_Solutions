#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

void update(ll& x, ll& o, char c) {
	x = c == 'x' ? x+1 : 0;
	o = c == 'o' ? o+1 : 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll L; cin >> L;
	ll x_wins = 0, o_wins = 0;
	while (L--) {
		ll M, N, K; cin >> M >> N >> K;
		vector<string> grid(N, "");
		rep(i, 0, N) cin >> grid[i];
		ll cnt_x, cnt_o;
		rep(row, 0, N) {
			cnt_x = cnt_o = 0;
			rep(col, 0, M) {
				update(cnt_x, cnt_o, grid[row][col]);
				if (cnt_x == K || cnt_o == K) goto end;
			}
		}
		rep(col, 0, M) {
			cnt_x = cnt_o = 0;
			rep(row, 0, N) {
				update(cnt_x, cnt_o, grid[row][col]);
				if (cnt_x == K || cnt_o == K) goto end;
			}
		}
		rep(diag, 1, N+M) {
			cnt_x = cnt_o = 0;
			ll i = max(0ll, N-diag);
			ll j = max(0ll, diag-N);
			while (i < N && j < M) {
				update(cnt_x, cnt_o, grid[i][j]);
				if (cnt_x == K || cnt_o == K) goto end;
				i++; j++;
			}
		}
		rep(diag, 1, N+M) {
			cnt_x = cnt_o = 0;
			ll i = min(diag-1, N-1);
			ll j = max(0ll, diag-N);
			while (i >= 0 && j < M) {
				update(cnt_x, cnt_o, grid[i][j]);
				if (cnt_x == K || cnt_o == K) goto end;
				i--; j++;
			}
		}
end:
		x_wins += cnt_x >= K;
		o_wins += cnt_o >= K;
	}
	printf("%lld:%lld\n", x_wins, o_wins);
}
