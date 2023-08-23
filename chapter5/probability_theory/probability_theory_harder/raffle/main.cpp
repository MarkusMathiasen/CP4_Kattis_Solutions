#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, p;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> p;
	ll x = 1;
	long double res = x*p/(long double)(n+1);
	rep(i, 2, x+1) res *= (n-p+i)/(long double)(n+i);
	long double val = res;
	for (; x <= (ll)5e6; x++) {
		val *= (x+1)/(long double)x*(n-p+x+1)/(n+x+1);
		res = max(res, val);
	}
	printf("%Lf\n", res);
}
