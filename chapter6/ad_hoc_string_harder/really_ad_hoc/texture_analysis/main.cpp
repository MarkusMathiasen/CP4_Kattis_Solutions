#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	ll t = 0;
	while ((cin >> s), s != "END") {
		printf("%lld ", ++t);
		bool res = true;
		ll pos = s.find('*', 1), dist = pos;
		ll npos;
		while ((npos = s.find('*', pos+1)) != -1) {
			res &= dist == npos-pos;
			pos = npos;
		}
		res |= s == "*";
		if (!res) printf("NOT ");
		printf("EVEN\n");
	}
}
