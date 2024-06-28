#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll M, N, ax, ay, bx, by;
double R;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N >> R >> ax >> ay >> bx >> by;
	double res = 1e9;
	rep(i, 0, min(ay, by)+1) {
		double att = 0;
		att += (double)(ay+by-2*i)*R/(double)N;
		att += (double)abs(ax-bx)/(double)M*M_PI*R*(double)i/(double)N;
		res = min(res, att);
	}
	printf("%.8lf\n", res);
}
