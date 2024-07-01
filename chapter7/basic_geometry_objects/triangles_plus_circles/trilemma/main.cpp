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

ll T;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		Point<ll> p1, p2, p3; cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		p1 = p1-p3; p2 = p2-p3; p3 = p2-p1;
		if (p1.cross(p2) == 0) printf("not a triangle\n");
		else {
			if (p1.dist2() == p2.dist2()
				|| p1.dist2() == p3.dist2()
				|| p2.dist2() == p3.dist2())
				printf("isosceles ");
			else printf("scalene ");
			if (p1.dot(p2) == 0
				|| p1.dot(p3*(-1)) == 0
				|| p2.dot(p3) == 0)
				printf("right");
			else if (p1.dot(p2) < 0
				|| p1.dot(p3*(-1)) < 0
				|| p2.dot(p3) < 0)
				printf("obtuse");
			else printf("acute");
			printf(" triangle\n");
		}
	}
}
