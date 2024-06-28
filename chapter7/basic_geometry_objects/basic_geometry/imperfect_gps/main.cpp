#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

template <class T> ll sgn(T x) { return (x > 0) - (x < 0); }
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

ll n, t;
vector<Point<double>> A, B;
vi times;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> t;
	A.assign(n, Point<double>());
	times.assign(n, 0);
	rep(i, 0, n) cin >> A[i].x >> A[i].y >> times[i];
	ll idx = 0, tim = 0;
	B.push_back(A[0]);
	while (idx < n-1) {
		while (idx < n-1 && tim >= times[idx+1]) idx++;
		B.push_back(tim == times[idx] ? A[idx] : A[idx] + (A[idx+1]-A[idx])*((double)(tim-times[idx])/(double)(times[idx+1]-times[idx])));
		tim += t;
		if (tim > times.back()) tim = times.back();
	}
	double actual_dist = 0;
	rep(i, 0, n-1) actual_dist += (A[i]-A[i+1]).dist();
	double measured_dist = 0;
	rep(i, 0, sz(B)-1) measured_dist += (B[i]-B[i+1]).dist();
	printf("%.8lf\n", (1 - measured_dist/actual_dist)*100);
}
