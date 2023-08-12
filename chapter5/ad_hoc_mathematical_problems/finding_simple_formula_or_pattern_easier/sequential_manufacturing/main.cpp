#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, p;
ll t_sum = 0, slow = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> p;
	rep(i, 0, n) {
		ll a; cin >> a;
		slow = max(slow, a);
		t_sum += a;
	}
	printf("%lld\n", t_sum+slow*(p-1));
}
