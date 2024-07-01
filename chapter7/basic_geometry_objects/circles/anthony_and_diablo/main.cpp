#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

double A, N;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> A >> N;
	printf(N*N/4./M_PI > A-1e-9 ? "Diablo is happy!\n" : "Need more materials!\n");
}
