#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	ll a = n/2, b = n/2+n%2;
	printf("%lld\n", (a+1)*(b+1));
}
