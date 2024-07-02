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
	T x, y, idx;
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
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h((int)sz(pts)+1);
	ll s = 0, t = 0;
	for (P p : pts) {
		while (t >= s + 2 && h[(int)t-2].cross(h[(int)t-1], p) < 0) t--;
		h[(int)t++] = p;
	}
	return {h.begin(), h.begin() + (int)t - (t == 2 && h[0] == h[1])};
}

ll T, n;
vector<Point<ll>> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		A.resize(n);
		rep(i, 0, n) (cin >> A[i].x >> A[i].y), A[i].idx = i;
		vector<Point<ll>> CH = convexHull(A);
		unordered_set<ll> hull;
		for (Point<ll> p : CH) hull.insert(p.idx);
		sort(A.rbegin(), A.rend());
		for (Point<ll> p : A) {
			if (!hull.count(p.idx)) CH.push_back(p);
		}
		for (Point<ll> P : CH) printf("%lld ", P.idx);
		printf("\n");
	}
}
