#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string key, msg;
vector<string> grid;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	getline(cin, key); getline(cin, msg);
	grid.assign(5, "     ");
	ll cnt = 0;
	set<char> seen = {' '};
	for (char c : key + "abcdefghijklmnoprstuvwxyz") {
		if (seen.count(c)) continue;
		seen.insert(c);
		grid[cnt/5][cnt%5] = (char)toupper(c);
		cnt++;
	}
	ll i = 0;
	msg.push_back('x');
	string msg2 = msg;
	msg = "";
	for (char c : msg2)
		if (c != ' ')
			msg.push_back((char)toupper(c));
	while (i < sz(msg)-1) {
		char a = msg[i], b = msg[i+1];
		i += 2;
		if (a == b) {
			b = 'X';
			i--;
		}
		ll r1, c1, r2, c2;
		rep(r, 0, 5) rep(c, 0, 5) {
			if (grid[r][c] == a) r1 = r, c1 = c;
			if (grid[r][c] == b) r2 = r, c2 = c;
		}
		if (r1 == r2)
			printf("%c%c", grid[r1][(c1+1)%5], grid[r2][(c2+1)%5]);
		else if (c1 == c2)
			printf("%c%c", grid[(r1+1)%5][c1], grid[(r2+1)%5][c2]);
		else
			printf("%c%c", grid[r1][c2], grid[r2][c1]);
	}
	printf("\n");
}
