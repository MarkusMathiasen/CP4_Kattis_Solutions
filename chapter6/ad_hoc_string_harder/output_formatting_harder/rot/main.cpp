#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vector<string> A;

void rot90() {
	vector<string> B(sz(A[0]), string(sz(A), ' '));
	rep(i, 0, sz(A)) rep(j, 0, sz(A[0]))
		B[j][sz(A)-1-i] = A[i][j];
	A = B;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m; cin >> n >> m;
	A.assign(n, "");
	rep(i, 0, n) cin >> A[i];
	ll deg; cin >> deg;
	while (deg >= 90) rot90(), deg -= 90;
	if (deg > 0) {
		ll k = sz(A)+sz(A[0])-1;
		vector<string> B(k, string(k, ' '));
		rep(i, 0, sz(A)) rep(j, 0, sz(A[0])) {
			B[i+j][sz(A)-1-i+j] = A[i][j];
		}
		rep(i, 0, k)
			while (B[i].back() == ' ')
				B[i].pop_back();
		A = B;
	}
	for (string s : A) {
		printf("%s\n", s.c_str());
	}
}
