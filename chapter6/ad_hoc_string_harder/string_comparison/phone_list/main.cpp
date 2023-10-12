#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		vector<string> A(n, "");
		rep(i, 0, n) cin >> A[i];
		sort(all(A));
		bool res = true;
		rep(i, 0, n-1)
			res &= sz(A[i]) > sz(A[i+1]) || A[i] != A[i+1].substr(0, sz(A[i]));
		printf(res ? "YES\n" : "NO\n");
	}
}
