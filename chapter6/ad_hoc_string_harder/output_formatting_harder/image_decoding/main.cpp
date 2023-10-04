#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string line;

ll print_line() {
	getline(cin, line);
	stringstream ss(line);
	char c; ss >> c;
	ll len, sum = 0;
	while (ss >> len) {
		sum += len;
		rep(i, 0, len) printf("%c", c);
		if (c == '#') c = '.';
		else c = '#';
	}
	printf("\n");
	return sum;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll rows;
	bool first = true;
	while ((cin >> rows), rows) {
		if (!first) printf("\n");
		first = false;
		ll len = -1;
		bool same = true;
		getline(cin, line);
		rep(i, 0, rows) {
			ll len2 = print_line();
			if (len == -1) len = len2;
			same &= len == len2;
		}
		if (!same) printf("Error decoding image\n");
	}
}
