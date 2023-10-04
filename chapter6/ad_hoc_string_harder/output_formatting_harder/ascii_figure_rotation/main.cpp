#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll rows, cols = 100;
string line;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	bool first = true;
	while ((cin >> rows), rows) {
		if (!first) printf("\n");
		first = false;
		getline(cin, line);
		vector<string> grid1(rows, ""), grid2(cols, "");
		rep(i, 0, rows)
			getline(cin, grid1[i]);
		rep(i, 0, cols) rep(j, 0, rows)
			grid2[i].push_back(' ');
		rep(i, 0, rows) rep(j, 0, sz(grid1[i])) {
			char c = grid1[i][j];
			grid2[j][rows-i-1] = c == '|' ? '-' : (c == '-' ? '|' : c);
		}
		rep(i, 0, sz(grid2)) while(grid2[i].back() == ' ')
			grid2[i].pop_back();
		while (grid2.back() == "")
			grid2.pop_back();
		rep(i, 0, sz(grid2))
			printf("%s\n", grid2[i].c_str());
	}
}
