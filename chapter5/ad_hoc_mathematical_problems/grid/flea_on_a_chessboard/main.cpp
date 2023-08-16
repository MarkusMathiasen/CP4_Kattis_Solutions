#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll S, x, y, dx, dy, mx, my;

bool is_white(ll x, ll y) {
	if (x == 0 || y == 0 || x == S || y == S)
		return false;
	return (x > S) ^ (y > S);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> S >> x >> y >> dx >> dy), S) {
		mx = x%(2*S), my = y%(2*S);
		set<pii> grid;
		ll cnt = 0;
		ll res = -1;
		while (!grid.count({mx,my})) {
			if (is_white(mx, my)) {
				res = cnt;
				break;
			}
			cnt++;
			grid.insert({mx, my});
			x += dx; mx = x%(2*S);
			y += dy; my = y%(2*S);
		}
		if (res == -1) printf("The flea cannot escape from black squares.\n");
		else printf("After %lld jumps the flea lands at (%lld, %lld).\n", cnt, x, y);
	}
}
