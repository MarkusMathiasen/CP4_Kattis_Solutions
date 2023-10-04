#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
string s;
vi dx = {1, 0, -1, 0}, dy = {0, -1, 0, 1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	printf("%lld\n", T);
	while (T--) {
		cin >> s;
		set<pii> paths;
		ll x = 0, y = 0, dir = 0; // east, south, west, north
		ll max_x = 0, max_y = 0, min_y = 0;
		for (char c : s) {
			if (c == 'R') dir = (dir+1)%4;
			else if (c == 'L') dir = (dir+3)%4;
			else if (c == 'B') dir = (dir+2)%4;
			else assert(c == 'F');
			x += dx[dir], y += dy[dir];
			paths.insert({x, y});
			max_x = max(max_x, x);
			max_y = max(max_y, y);
			min_y = min(min_y, y);
		}
		ll h = max_y - min_y + 3;
		ll w = max_x + 2;
		printf("%lld %lld\n", h, w);
		for (y = max_y+1; y >= min_y-1; y--) {
			for (x = 0; x <= max_x+1; x++)
				printf(paths.count({x, y}) ? "." : "#");
			printf("\n");
		}
	}

}
