#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		A.assign(n, 0);
		rep(i, 0, n) {
			cin >> A[i];
			A[i]--;
		}
		rep(j, 0, n) {
			vi B(all(A));
			rep(i, 0, n) A[i] = B[A[i]];
		}
		bool res = true;
		rep(i, 0, n) res &= A[i] == i;
		if (res) printf("All can eat.\n");
		else printf("Some starve.\n");
	}
}
