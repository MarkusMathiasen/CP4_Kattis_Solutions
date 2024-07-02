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
typedef Point<ll> P;
void convexHull(vector<P>& pts, vector<P>& h) {
	if (sz(pts) <= 1) {
		h[0] = pts[0];
		return;
	};
	sort(all(pts));
	ll s = 0, t = 0;
	for (ll it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	h.resize(t - (t==2 && h[0] == h[1]));
}

ll n;
vector<Point<ll>> A, h;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	assert(n <= 100000);
	A.resize(n);
	h.resize(n+1);
	rep(i, 0, n) cin >> A[i].x >> A[i].y;
	convexHull(A, h);
	n = sz(h);
	assert(n <= 100000);
	ll j = 0, nxt_j;
	ll res = 0, cnt = 0;
	rep(i, 0, n) rep(j, 0, n) {
		res = max(res, (h[i]-h[j]).dist2());
	}
	printf("%lf\n", sqrt(res));
}
