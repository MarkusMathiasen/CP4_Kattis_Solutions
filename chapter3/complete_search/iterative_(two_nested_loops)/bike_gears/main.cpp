#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
	ll F, B; scanf("%lld%lld", &F, &B);
	vector<ll> front(F, 0), back(B, 0);
	for (ll i = 0; i < F; i++)
		scanf("%lld", &front[i]);
	for (ll i = 0; i < B; i++)
		scanf("%lld", &back[i]);
	vector<ii> gears;
	for (ll i = 0; i < F; i++)
		for (ll j = 0; j < B; j++)
			gears.push_back(ii(front[i], back[j]));
	sort(gears.begin(), gears.end(), [](const ii& a, const ii& b) {
		if (a.first * b.second != b.first*a.second)
			return a.first*b.second < b.first*a.second;
		return a.first < b.first;
	});
	for (auto& [f,b] : gears)
		printf("(%lld,%lld)\n", f, b);
}
