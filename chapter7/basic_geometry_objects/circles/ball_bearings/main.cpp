#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
double D, d, s, eps = 1e-8;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> D >> d >> s;
		double r = (D-d)/2.;
		double low = 0, high = 2*M_PI;
		while (low+eps < high) {
			double mid = (low+high)/2;
			if ((cos(mid)*r-r)*(cos(mid)*r-r) + sin(mid)*r*sin(mid)*r < (s+d)*(s+d))
				low = mid;
			else
				high = mid; 
		}
		ll res = (ll)floor(2.*M_PI / low);
		printf("%lld\n", res);
	}
}
