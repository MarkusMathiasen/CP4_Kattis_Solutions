#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

typedef double d;
#define S(a,b) (f(a) + 4*f((a+b) / 2) + f(b)) * (b-a) / 6

template <class F>
d rec(F& f, d a, d b, d eps, d S) {
	d c = (a + b) / 2;
	d S1 = S(a, c), S2 = S(c, b), T = S1 + S2;
	if (abs(T - S) <= 15 * eps || b - a < 1e-10)
		return T + (T - S) / 15;
	return rec(f, a, c, eps / 2, S1) + rec(f, c, b, eps / 2, S2);
}
template<class F>
d quad(d a, d b, F f, d eps = 1e-8) {
	return rec(f, a, b, eps, S(a, b));
}

struct sphere {
	double x, y, z, r;
	double volume() { return 4./3.*M_PI*r*r*r; }
};

ll n, s;
vector<sphere> A;
const double S = 100000., eps = 1e-8;

double f(double x) {return x - x*x*x/3.;}

double sphere_cut(double a, double b, double r) {
	return (f(b)-f(a))*M_PI*r*r*r;
}

double vol(double cut) {
	double res = S*S*cut;
	for (sphere s : A) {
		if (cut < s.z-s.r) continue;
		else if (s.z+s.r < cut) res -= s.volume();
		else res -= sphere_cut(-1, (cut-s.z)/s.r, s.r);
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	A.resize(n);
	rep(i, 0, n) cin >> A[i].r >> A[i].x >> A[i].y >> A[i].z;
	double total = S*S*S;
	for (sphere s : A) total -= s.volume();
	double inc = total/(double)s;
	vector<double> res = {0};
	rep(i, 1, s) {
		double low = 0, high = 100000;
		while (low+eps < high) {
			double mid = (low + high) / 2.;
			double v = vol(mid);
			if (v < (double)i*inc) low = mid;
			else high = mid;
		}
		res.push_back(low);
	}
	res.push_back(100000);
	rep(i, 1, s+1) printf("%.7lf ", (res[i]-res[i-1])/1000.);
	printf("\n");
}
