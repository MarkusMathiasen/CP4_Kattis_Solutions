#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

template<class F>
double quad(double a, double b, F f, const ll n = 100000) {
	double h = (b - a) / 2 / (double)n, v = f(a) + f(b);
	rep(i,1,n*2) v += f(a + (double)i*h) * (i&1 ? 4 : 2);
	return v * h / 3;
}

double f(double a, double b, double x) {
	return a*exp(-x*x) + b*sqrt(x);
}
double f2(double a, double b, double x) {
	double res = f(a, b, x);
	return res*res;
}

double V;
ll n;
vector<double> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> V >> n;
	rep(i, 0, n) {
		double a, b, h; cin >> a >> b >> h;
		A.push_back(quad(0, h, [a,b](double x){return M_PI*f2(a, b, x);}));
	}
	double dist = 1e18;
	ll res = -1;
	rep(i, 0, n) if (abs(A[i]-V) < dist) {
		res = i; dist = abs(A[i]-V);
	}
	// for (double x : A) printf("%lf\n", x);
	printf("%lld\n", res);

}
