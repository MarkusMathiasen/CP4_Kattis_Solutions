#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
vi p;
string s, res;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		p.assign(n, 0);
		rep(i, 0, n) {cin >> p[i]; p[i]--;}
		getline(cin, s); getline(cin, s);
		while (sz(s)%n) s.push_back(' ');
		res.assign(sz(s), '!');
		rep(i, 0, sz(s)/n) rep(j, 0, sz(p))
			res[i*n+j] = s[i*n+p[j]];
		printf("'%s'\n", res.c_str());
	}
}
