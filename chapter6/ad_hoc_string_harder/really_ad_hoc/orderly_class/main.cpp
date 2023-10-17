#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string A, B; cin >> A >> B;
	ll first = -1, last = -1;
	rep(i, 0, sz(A)) if (A[i] != B[i]) {
		if (first == -1) first = i;
		last = i;
	}
	reverse(A.begin()+first, A.begin()+last+1);
	ll res = A == B;
	if (!res) {
		printf("0\n"); return 0;
	}
	while ((--first >= 0 && ++last < sz(A)) && A[first] == A[last])
		res++;
	printf("%lld\n", res);
}
