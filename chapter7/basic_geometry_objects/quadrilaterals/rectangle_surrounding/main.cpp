#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct Point {
	ll x, y;
};
struct Rect {
	Point a, b;
	bool contains(Point p) const {return a.x <= p.x && a.y <= p.y && p.x < b.x && p.y < b.y; }
};

ll n;
vector<Rect> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		A.resize(n);
		rep(i, 0, n) cin >> A[i].a.x >> A[i].a.y >> A[i].b.x >> A[i].b.y;
		ll res = 0;
		rep(i, 0, 500) rep(j, 0, 500) {
			Point p = {i, j};
			bool b = false;
			rep(i, 0, n) b |= A[i].contains(p);
			res += b;
		}
		printf("%lld\n", res);
	}
}
