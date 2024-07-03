#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

double sphericalDistance(double f1, double t1,
		double f2, double t2, double r) {
	double dx = sin(t2)*cos(f2) - sin(t1)*cos(f1);
	double dy = sin(t2)*sin(f2) - sin(t1)*sin(f1);
	double dz = cos(t2) - cos(t1);
	double d = sqrt(dx*dx + dy*dy + dz*dz);
	return r*2*asin(d/2);
}

ll n;
vector<pair<double, double>> A, B;
const double eps = 1e-8;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		A.resize(n);
		B.resize(n);
		rep(i, 0, n) cin >> A[i].first >> A[i].second;
		rep(i, 0, n) B[i] = {(A[i].first+90.)*M_PI/180., A[i].second*M_PI/180.};
		ll res = -1;
		double dist = 1e9;
		rep(i, 0, n) {
			double att = 0;
			rep(j, 0, n) att = max(att, sphericalDistance(B[i].second, B[i].first, B[j].second, B[j].first, 1));
			if (att < dist + eps) {
				dist = att;
				res = i;
			}
		}
		printf("%.2lf %.2lf\n", A[res].first, A[res].second);
	}
}
