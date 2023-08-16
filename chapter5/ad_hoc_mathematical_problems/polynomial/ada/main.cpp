#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll n;
vector<vi> A;

int main() {
	// Read input
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vi v;
	rep(i, 0, n) {
		ll x; cin >> x;
		v.push_back(x);
	}
	A.push_back(v);
	// Build remaining layers
	while (sz(A.back()) > 1) {
		v.clear();
		rep(i, 0, sz(A.back())-1)
			v.push_back(A.back()[i+1]-A.back()[i]);
		A.push_back(v);
	}
	// compute res
	ll res = sz(A)-1;
	for (int i = sz(A)-2; i >= 0; i--) {
		bool equal = true;
		rep(k, 1, sz(A[i])) equal &= A[i][k] == A[i][0];
		if (equal)
			res = i;
		A[i].push_back(A[i].back()+A[i+1].back());
	}
	printf("%lld %lld\n", res, A[0].back());
}
