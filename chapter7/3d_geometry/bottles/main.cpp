#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const double eps = 1e-8;
ll n;
vector<double> A, As;
double x_low, x_high, inc;

double integrate(double x) {
	double res = 0;
	rep(i, 0, 2*n+1) res += As[i]/(double)(i+1) * pow(x, i+1);
	return res*M_PI;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t = 1;
	while (cin >> n) {
		A.resize(n+1);
		rep(i, 0, n+1) cin >> A[i];
		cin >> x_low >> x_high >> inc;
		As.assign(2*n+1, 0);
		rep(i, 0, n+1) rep(j, 0, n+1) As[i+j] += A[i]*A[j];
		double il = integrate(x_low), ih = integrate(x_high);
		printf("Case %lld: %.2lf\n", t++, ih - il);
		ll itt = 0;
		while (itt++ < 8) {
			double low = x_low, high = x_high;
			while (low+eps < high) {
				double mid = (low + high)/2.;
				if (integrate(mid)-il < inc*(double)itt)
					low = mid;
				else
					high = mid;
			}
			if (low+eps > x_high) break;
			printf("%.2lf ", low-x_low);
		}
		if (itt == 1) printf("insufficient volume");
		printf("\n");
	}
}
