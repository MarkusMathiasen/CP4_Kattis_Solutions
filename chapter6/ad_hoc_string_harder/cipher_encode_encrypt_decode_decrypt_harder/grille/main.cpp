#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
vector<vector<bool>> grille;
string s, res;

bool valid() {
	rep(i, 0, n) rep(j, 0, n) {
		int found = grille[i][j];
		found += grille[j][n-i-1];
		found += grille[n-i-1][n-j-1];
		found += grille[n-j-1][i];
		if (found != 1) return false;
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	grille.assign(n, vector<bool>(n, 0));
	rep(i, 0, n) rep(j, 0, n) {
		char c; cin >> c;
		grille[i][j] = c == '.';
	}
	cin >> s;
	if (!valid()) {
		printf("invalid grille\n");
		return 0;
	}
	res.assign(sz(s), '.');
	ll idx = 0;
	rep(i, 0, n) rep(j, 0, n) if (grille[i][j])
		res[i*n+j] = s[idx++];
	rep(i, 0, n) rep(j, 0, n) if (grille[n-j-1][i])
		res[i*n+j] = s[idx++];
	rep(i, 0, n) rep(j, 0, n) if (grille[n-i-1][n-j-1])
		res[i*n+j] = s[idx++];
	rep(i, 0, n) rep(j, 0, n) if (grille[j][n-i-1])
		res[i*n+j] = s[idx++];
	printf("%s\n", res.c_str());
}
