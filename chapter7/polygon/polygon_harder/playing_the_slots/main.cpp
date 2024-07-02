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
template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)a.cross(b, p)/(b-a).dist();
}

ll n;
vector<Point<ll>> A;

void read_real(ll& x) {
	string s; cin >> s;
	ll dot = -1;
	rep(i, 0, sz(s)) if (s[i] == '.') dot = i;
	if (dot == -1) x = 100*stoll(s);
	else x = 100*stoll(s.substr(0, dot)) + stoll(s.substr(dot+1, sz(s)-dot-1))*(dot==sz(s)-2 ? 10 : 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.resize(n);
	string x, y;
	rep(i, 0, n) read_real(A[i].x), read_real(A[i].y);
	double res = 1e9;
	rep(i, 0, n) {
		double att = 0;
		rep(j, 0, n)
			att = max(att, abs(lineDist(A[i], A[(i+1)%n], A[j])));
		res = min(res, att);
	}
	printf("%lf\n", res/100.);
}
