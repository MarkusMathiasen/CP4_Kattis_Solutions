#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const double eps = 1e-9;

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

double angle(ll a, ll b, ll c) {
	Point<ll> p1 = A[a] - A[b], p2 = A[c] - A[b];
	return acos((double)p1.dot(p2)/(p1.dist()*p2.dist()));
}

bool cuttable(ll c) {
	ll a = (c-2+sz(A))%sz(A), b = (a+1)%sz(A), d = (b+2)%sz(A), e = (d+1)%sz(A);
	double t = angle(b, c, d);
	return angle(a, b, d) + eps > t && angle(b, d, e) + eps > t;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n > 0) {
		A.resize(n);
		rep(i, 0, n) cin >> A[i].x >> A[i].y;
		while (sz(A) > 3) {
			double sharpest = M_PI;
			ll sharp = -1;
			bool cut = false;
			rep(i, 0, sz(A)) {
				double t = angle((i-1+sz(A))%sz(A), i, (i+1)%sz(A));
				if (t + eps < sharpest || (t - eps < sharpest && !cut)) {
					sharpest = t;
					sharp = i;
					cut = cuttable(i);
				}
			}
			if (!cut) break;
			assert(sharp != -1);
			A.erase(A.begin()+sharp);
		}
		printf("%lld", sz(A));
		for (Point<ll> p : A) printf(" %lld %lld", p.x, p.y);
		printf("\n");
	}
}
