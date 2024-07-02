#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n, m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(t, 1, T+1) {
		cin >> t >> n >> m;
		vector<double> r(m, 0), R(m, 0);
		double S = sin(M_PI/(double)n), C = cos(M_PI/(double)n);
		r[0] = S/(1.-S);
		R[0] = 1+r[0];
		rep(i, 1, m) {
			double a = C*C;
			double b = -2.*(C*R[i-1] + S*r[i-1]);
			double c = R[i-1]*R[i-1]-r[i-1]*r[i-1];
			R[i] = (-b + sqrt(b*b - 4.*a*c))/(2.*a);
			r[i] = S*R[i];
		}
		double outer = 2.*M_PI*r[m-1] + 2*r[m-1]*(double)n;
		printf("%lld %.3lf %.3lf\n", t, r[m-1], outer);
	}
}
