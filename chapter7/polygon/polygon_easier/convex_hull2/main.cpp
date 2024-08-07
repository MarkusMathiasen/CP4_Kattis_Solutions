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

ll n;
vector<Point<ll>> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 0, n) {
		Point<ll> p; char c; cin >> p.x >> p.y >> c;
		if (c == 'Y') A.push_back(p);
		else assert(c == 'N');
	}
	sort(all(A));
	Point<ll> avg;
	rep(i, 0, sz(A)) avg = avg + A[i];
	avg = avg/sz(A);
	Point<ll> o = A[0];
	sort(A.begin()+1, A.end(), [o](const Point<ll>& a, const Point<ll>& b) {
		if (o.cross(a, b) > 0) return true;
		if (o.cross(a, b) < 0) return false;
		if (a.x != b.x) return a.x < b.x;
		return a.y > b.y;
	});
	printf("%lld\n", sz(A));
	for (Point<ll> p : A) printf("%lld %lld\n", p.x, p.y);
}
