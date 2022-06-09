#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Q, M, S, L;

bool check(ll t) {
	if (Q*L + S > M*t)
		return false;
	return t/Q * M >= L;
}

int main() {
	scanf("%lld%lld%lld%lld", &Q, &M, &S, &L);
	ll low = 0, high = 2e9;
	while (low < high) {
		ll mid = (low + high)/2;
		if (check(mid))
			high = mid;
		else
			low = mid+1;
	}
	printf("%lld\n", low);
}
