#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll n;
vi fact = {1};

int main() {
	for (ll i = 1; fact.back() < (ll)1e15; i++)
		fact.push_back(fact.back()*i);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	long double res = 0;
	for (ll i = 0; i <= min(n, (ll)sz(fact)-1); i++)
		res += 1.0L/fact[i];
	printf("%.13Lf\n", res);
}
