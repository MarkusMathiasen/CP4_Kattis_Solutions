#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll K = 10000;

ll n;
string s;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 0, n) {
		cin >> s >> s;
		ll a, b; sscanf(s.c_str(), "%lld.%lld", &a, &b);
		A.push_back(a*K+b);
	}
	sort(A.rbegin(), A.rend());
	ll res = 0;
	rep(i, 0, n)
		res += (i+1)*A[i];
	printf("%lld.%04lld\n", res/K, res%K);
}
