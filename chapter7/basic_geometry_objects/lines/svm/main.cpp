#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll d;
vector<double> w, x;
double b, w_norm;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> d;
	w.assign(d, 0);
	rep(i, 0, d) cin >> w[i];
	w_norm = 0;
	rep(i, 0, d) w_norm += w[i]*w[i];
	w_norm = sqrt(w_norm);
	cin >> b;
	x.assign(d, 0);
	while (cin >> x[0]) {
		rep(i, 1, d) cin >> x[i];
		double res = b;
		rep(i, 0, d) res += x[i]*w[i];
		printf("%.8lf\n", res/w_norm);
	}
}
