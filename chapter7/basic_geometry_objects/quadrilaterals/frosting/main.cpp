#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, A[3], total[3], tmp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 0, n) (cin >> tmp), A[(i+1)%3] += tmp;
	rep(i, 0, n) {
		cin >> tmp;
		rep(j, 0, 3) total[(i+1+j)%3] += tmp*A[j];
	}
	for (ll x : total) printf("%lld ", x);
	printf("\n");
}
