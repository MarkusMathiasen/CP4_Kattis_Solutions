#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, r, n;
double p[50];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	p[0] = 1;
	rep(i, 1, 50) p[i] = p[i-1]*3./4.;
	rep(i, 1, 50) p[i] += p[i-1];
	cin >> T;
	while (T--) {
		cin >> r >> n;
		double C0 = (double)(r*r)*M_PI;
		printf("%.8lf\n", C0 + C0*(n >= 2 ? p[n-2] : 0));
	}
}
