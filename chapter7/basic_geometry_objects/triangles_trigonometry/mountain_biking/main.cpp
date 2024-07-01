#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
double g;
vector<double> A, S;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> g;
	rep(i, 0, n) {
		double d, t; cin >> d >> t;
		A.push_back(g*cos(t/180.*M_PI));
		S.push_back(d);
	}
	rep(i, 0, n) {
		double v0 = 0;
		rep(j, i, n) v0 = sqrt(v0*v0 + 2*A[j]*S[j]);
		printf("%.8lf\n", v0);
	}
}
