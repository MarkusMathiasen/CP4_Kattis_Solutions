#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> res;
ll d;

ll valid(ll cn, ll n) {
	ll n_pow = 10;
	for (ll i = 0; i < n; i++)
		n_pow *= 10;
	ll x_diff = 100000l-d;
	ll top = 10000l*cn*(n_pow-1);
	if (top % x_diff)
		return 0;
	ll result = top / x_diff;
	while (result >= 10)
		result /= 10;
	if (result == cn)
		return top/x_diff;
	else
		return 0;
}

int main() {
	double x; scanf("%lf", &x);
	d = x*10000 + 0.00001;
	if (d >= 100000) {
		printf("No solution\n");
		return 0;
	}
	for (ll i = 1; i < 10; i++)
		for (ll n = 0; n < 8; n++)
			if (valid(i, n))
				res.push_back(valid(i, n));
	sort(res.begin(), res.end());
	if (res.size())
		for (ll y : res)
			printf("%lld\n", y);
	else
		printf("No solution\n");
}
