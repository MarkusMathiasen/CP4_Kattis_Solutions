#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 50000;

ll p, q;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> p >> q), p || q) {
		ll d = gcd(p, q);
		p /= d; q /= d;
		if (p == 0) {
			printf("0 2\n");
			continue;
		}
		ll r = 2;
		ll b = 0;
		ll np = 1, nq = 1;
		while (np*q != p*nq) {
			if (np*q < p*nq) r++;
			else b++;
			if (r+b > N) break;
			np = r*(r-1);
			nq = (r+b)*(r+b-1);
			d = gcd(np, nq);
			np /= d;
			nq /= d;
		}
		if (r+b > N) printf("impossible\n");
		else printf("%lld %lld\n", r, b);
	}
}
