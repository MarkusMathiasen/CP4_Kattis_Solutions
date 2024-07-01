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

ll T, n, A, B, C, D, x0, y, M;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(t, 1, T+1) {
		cin >> n >> A >> B >> C >> D >> x0 >> y >> M;
		vector<Point<ll>> trees;
		trees.push_back(Point<ll>(x0, y));
		rep(i, 1, n) {
			x0 = (A*x0 + B) % M;
			y = (C*y + D) % M;
			trees.push_back(Point<ll>(x0, y));
		}
		ll res = 0;
		rep(i, 0, n) rep(j, i+1, n) rep(k, j+1, n) {
			Point<ll> p = trees[i] + trees[j] + trees[k];
			res += p.x % 3 == 0 && p.y % 3 == 0;
		}
		printf("Case #%lld: %lld\n", t, res);
	}
}
