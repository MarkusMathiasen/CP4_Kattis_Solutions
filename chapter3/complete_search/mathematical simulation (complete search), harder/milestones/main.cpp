#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int M, N; scanf("%d%d", &M, &N);
	vector<ll> times(M, 0);
	vector<ll> stones(N, 0);
	for (int i = 0; i < M; i++)
		scanf("%lld", &times[i]);
	for (int i = 0; i < N; i++)
		scanf("%lld", &stones[i]);
	set<ll> res;
	for (int start = 0; start <= N-M; start++) {
		ll ds = stones[start+1] - stones[start];
		ll dt = times[1] - times[0];
		bool valid = true;
		for (int t = 0; t < M && valid; t++) {
			valid &= ((times[t]-times[0])*ds)%dt == 0;
			ll inc = (times[t]-times[0])*ds/dt;
			valid &= stones[start+t] == stones[start]+inc;
		}
		if (valid)
			res.insert(ds);
	}
	printf("%ld\n", res.size());
	for (ll x : res)
		printf("%lld ", x);
	printf("\n");
}
