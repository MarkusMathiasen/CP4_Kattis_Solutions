#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, low, high;
vector<ll> primes;
vector<ll> res;

void rec(ll num, int idx) {
	if (idx >= N || num > high)
		return;
	rec(num, idx+1);
	ll nxt_num = num*primes[idx];
	rec(nxt_num, idx);
	if (nxt_num <= high && nxt_num >= low)
		res.push_back(nxt_num);
}

int main() {
	while (scanf("%lld", &N), N) {
		res.clear();
		primes.assign(N, 0);
		for (int i = 0; i < N; i++)
			scanf("%lld", &primes[i]);
		scanf("%lld%lld", &low, &high);
		if (low == 1ll)
			res.push_back(1ll);
		rec(1ll, 0);
		sort(res.begin(), res.end());
		if (!res.size())
			printf("none");
		else {
			printf("%lld", res[0]);
			for (int i = 1; i < (int)res.size(); i++)
				printf(",%lld", res[i]);
		}
		printf("\n");
	}
}
