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

const ll max_step = 450;
ll n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<Point<ll>> A, B;
	rep(i, 1, max_step) rep(j, 1, max_step) A.push_back(Point<ll>(i, j));
	sort(all(A), [](const Point<ll>& a, const Point<ll>& b) {
		if (a.cross(b) > 0) return true;
		return a.cross(b) == 0 && a.x+a.y < b.x+b.y;
	});
	B.push_back(A[0]);
	for (Point<ll> p : A) {
		assert(B.back().cross(p) >= 0);
		if (B.back().cross(p) > 0) B.push_back(p);
	}
	sort(all(B), [](const Point<ll>& a, const Point<ll>& b) {
		return a.dist2() < b.dist2();
	});
	while (sz(B) > 100000) B.pop_back();
	sort(all(B), [](const Point<ll>& a, const Point<ll>& b) {
		return a.cross(b) > 0;
	});
	ll k = sz(B);
	rep(itt, 0, 3) rep(i, k*itt, k*(itt+1)) B.push_back(B[i].perp());
	rep(i, 1, sz(B)) B[i] = B[i] + B[i-1];
	for (Point<ll>& p : B) p.x += (ll)2e7;
	for (Point<ll> p : B) assert(0 <= p.x && p.x <= (ll)4e7);
	rep(i, 0, n) printf("%lld %lld\n", B[i].x, B[i].y);
}
