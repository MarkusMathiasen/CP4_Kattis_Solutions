#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, k;
vector<long double> s, res;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	s.assign(n, 0);
	res.assign(n, 0);
	rep(i, 0, n) {
		cin >> s[i];
		s[i] /= 100;
	}
	rep(mon, 0, n) {
		res[mon] += s[mon]*k/n;
		long double prob = 1;
		rep(i, 1, n) {
			ll p = (mon+i)%n;
			prob *= (long double)(n-k-i+1)/(n-i+1);
			if (prob == 0) break;
			res[p] += s[mon]*prob*k/(n-i);
		}
	}
	for (long double x : res) printf("%Lf ", x*100);
	printf("\n");
}
