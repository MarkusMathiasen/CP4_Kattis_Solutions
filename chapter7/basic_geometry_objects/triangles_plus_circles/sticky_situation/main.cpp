#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.assign(n, 0);
	rep(i, 0, n) cin >> A[i];
	sort(all(A));
	bool res = false;
	rep(i, 0, n-2) res |= A[i] + A[i+1] > A[i+2];
	if (!res) printf("im");
	printf("possible\n");
}
