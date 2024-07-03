#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

double w;

double dx2(double t) {
	double res = 1 + cos(t-w) - cos(t);
	return res*res;
}
double dy2(double t) {
	double res = sin(t-w) - sin(t);
	return res*res;
}
double dz2(double t) {
	double res = t-2*w;
	return res*res;
}
double dist2(double t) {
	return dx2(t) + dy2(t) + dz2(t);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> w;
	double res = 9;
	for (double t = 2*w-M_PI; t <= 2*w+M_PI; t += 1e-5) {
		res = min(res, dist2(t));
	}
	printf("%lf\n", sqrt(res));
}
