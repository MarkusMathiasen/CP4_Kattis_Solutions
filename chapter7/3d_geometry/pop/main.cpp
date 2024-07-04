#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

template<class T> struct Point3D {
	typedef Point3D P;
	typedef const P& R;
	T x, y, z;
	explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(R p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z); }
	bool operator==(R p) const {
		return tie(x, y, z) == tie(p.x, p.y, p.z); }
	P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(R p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; }
	double dist() const { return sqrt((double)dist2()); }
	//Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
	double phi() const { return atan2(y, x); } 
	//Zenith angle (latitude) to the z-axis in interval [0, pi]
	double theta() const { return atan2(sqrt(x*x+y*y),z); }
	P unit() const { return *this/(T)dist(); } //makes dist()=1
	//returns unit vector normal to *this and p
	P normal(P p) const { return cross(p).unit(); }
	//returns point rotated 'angle' radians ccw around axis
	P rotate(double angle, P axis) const {
		double s = sin(angle), c = cos(angle); P u = axis.unit();
		return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
	}
};

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	if ((b-a).dot(p-a) < 0) return (p-a).dist();
	return (double)(b-a).cross(p-a).dist()/(b-a).dist();
}

ll n, m;
vector<Point3D<double>> A;
vector<double> r;
const double eps = 1e-8;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n>0) {
		A.resize(n);
		r.resize(n);
		rep(i, 0, n) (cin >> r[i] >> A[i].z >> A[i].x >> A[i].y), A[i].z += r[i];
		cin >> m;
		vi shot(n, 0);
		while (m--) {
			Point3D<double> p, v; cin >> p.x >> p.y >> p.z >> v.x >> v.y >> v.z;
			ll res = 0;
			rep(i, 0, n) {
				double d = lineDist(p, p+v, A[i]);
				if (d < r[i]+eps && !shot[i]) {
					shot[i] = true;
					res++;
				}
			}
			printf("%lld\n", res);
		}
	}
}
