#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string s;
set<pii> m = {{0, 0}};
ll max_x = 0, min_x = 0, max_y = 0, min_y = 0, x = 0, y = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (getline(cin, s) && s != "") {
		if (s == "up") y++;
		if (s == "down") y--;
		if (s == "left") x--;
		if (s == "right") x++;
		max_x = max(max_x, x);
		max_y = max(max_y, y);
		min_x = min(min_x, x);
		min_y = min(min_y, y);
		m.insert({x, y});
	}
	rep(i, min_x-1, max_x+2) printf("#");
	printf("\n");
	for (ll row = max_y; row >= min_y; row--) {
		printf("#");
		rep(col, min_x, max_x+1) {
			if (row == 0 && col == 0) printf("S");
			else if (row == y && col == x) printf("E");
			else if (m.count({col, row})) printf("*");
			else printf(" ");
		}
		printf("#\n");
	}
	rep(i, min_x-1, max_x+2) printf("#");
	printf("\n");
}
