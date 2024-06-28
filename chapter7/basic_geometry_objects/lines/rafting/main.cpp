#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	assert(!(s == e));
	double d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

ll T, a, b;
vector<P> A, B;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> a;
		A.assign(a, P());
		rep(i, 0, a) cin >> A[i].x >> A[i].y;
		cin >> b;
		B.assign(b, P());
		rep(i, 0, b) cin >> B[i].x >> B[i].y;
		double res = 1e9;
		rep(i, 0, a) {
			res = min(res, segDist(B.front(), B.back(), A[i]));
			rep(j, 0, b-1) res = min(res, segDist(B[j], B[j+1], A[i]));
		}
		rep(i, 0, b) {
			res = min(res, segDist(A.front(), A.back(), B[i]));
			rep(j, 0, a-1) res = min(res, segDist(A[j], A[j+1], B[i]));
		}
		printf("%.8lf\n", res/2);
	}
}
