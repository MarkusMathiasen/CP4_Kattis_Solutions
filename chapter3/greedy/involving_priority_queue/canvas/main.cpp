#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		ll res = 0;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < N; i++) {
			ll x; scanf("%lld", &x);
			pq.push(x);
		}
		while (pq.size() >= 2) {
			ll x = pq.top(); pq.pop();
			x += pq.top(); pq.pop();
			pq.push(x);
			res += x;
		}
		printf("%lld\n", res);
	}
}
