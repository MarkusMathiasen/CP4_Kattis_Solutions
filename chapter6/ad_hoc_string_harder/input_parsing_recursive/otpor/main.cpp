#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
vector<double> R;
string s;

double calc(ll& i) {
	i++;
	vector<double> vals;
	bool par = false;
	while (s[i] != ')') {
		if (s[i] == '(')
			vals.push_back(calc(i));
		else if (s[i] == '|') par = true;
		else if (s[i] == 'R') {
			i++;
			vals.push_back(R[s[i]-'1']);
		}
		else assert(s[i] == '-');
		i++;
	}
	double res = 0;
	for (double x : vals)
		if (par) res += 1/x;
		else res += x;
	if (par) res = 1/res;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	R.assign(n, 0);
	rep(i, 0, n) cin >> R[i];
	cin >> s;
	ll pos = 0;
	double res = calc(pos);
	printf("%lf\n", res);
}
