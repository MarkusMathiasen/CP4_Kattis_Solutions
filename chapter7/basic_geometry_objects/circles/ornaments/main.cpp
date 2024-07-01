#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll r, h, s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> r >> h >> s), (r||h||s)) {
		double t = sqrt(h*h-r*r);
		double a = 2.*acos((double)r/(double)h);
		double l = 2*t + (2*M_PI-a)*(double)r;
		printf("%.2lf\n", l*(double)(100+s)/100.);
	}
}
