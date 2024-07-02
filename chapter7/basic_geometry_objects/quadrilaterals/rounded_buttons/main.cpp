#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const double eps = 1e-9;

struct point {
	double x, y;
	point(double x, double y) : x(x), y(y) {}
	point() {}
};

double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct rect {
	point a, b;
	rect(double x, double y, double w, double h) : a(x, y), b(x+w, y+h) {}
	bool contains(point p) const { return a.x <= p.x && a.y <= p.y && b.x >= p.x && b.y >= p.y; }
};
struct button {
	rect rec;
	double r;
	point ul, ur, ll, lr;
	button(rect rec, double r) : rec(rec), r(r) {
		ul = {rec.a.x+r, rec.b.y-r};
		ur = {rec.b.x-r, rec.b.y-r};
		ll = {rec.a.x+r, rec.a.y+r};
		lr = {rec.b.x-r, rec.a.y+r};
	}
	bool contains(point p) const {
		if (!rec.contains(p)) return false;
		if (p.x < ul.x && p.y > ul.y && dist(ul, p) > r+eps) return false;
		if (p.x < ll.x && p.y < ll.y && dist(ll, p) > r+eps) return false;
		if (p.x > ur.x && p.y > ur.y && dist(ur, p) > r+eps) return false;
		if (p.x > lr.x && p.y < lr.y && dist(lr, p) > r+eps) return false;
		return true;
	}
};

ll T, m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		double x, y, w, h, r; cin >> x >> y >> w >> h >> r;
		button b(rect(x, y, w, h), r);
		ll m; cin >> m;
		while (m--) {
			point p(0, 0); cin >> p.x >> p.y;
			printf(b.contains(p) ? "inside\n" : "outside\n");
		}
		printf("\n");
	}
}
