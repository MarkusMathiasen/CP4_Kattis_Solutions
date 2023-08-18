#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 10001;

vi euler_phi(N, -1);
vi pre_phi(N, 0);

void fill_euler_phi() {
	rep(i, 1, N) euler_phi[i] = i;
	rep(i, 2, N) if (euler_phi[i] == i) // is prime
		for (ll j = i; j < N; j += i) // all this is prime factor of
			euler_phi[j] = euler_phi[j]*(i-1)/i;
	rep(i, 1, N) pre_phi[i] = pre_phi[i-1]+euler_phi[i];
}

ll T, t, n;

int main() {
	fill_euler_phi();
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> t >> n;
		printf("%lld %lld\n", t, pre_phi[n]+1);
	}
}
