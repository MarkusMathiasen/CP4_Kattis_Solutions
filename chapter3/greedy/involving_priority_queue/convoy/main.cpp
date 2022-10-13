#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct que {
	ll t; // time
	ll p; // people
	ll s; // speed
	que(ll t, ll p, ll s) : t(t), p(p), s(s) {}
	bool operator<(const que& a) const {
		return t > a.t;
	}
};

int main() {
	int n, k; scanf("%d%d", &n, &k);
	priority_queue<que> pq;
	vector<ll> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	sort(A.begin(), A.end());
	for (int i = 0; i < min(n, k); i++)
		pq.emplace(A[i], 5, A[i]);
	ll p = 0;
	ll res = 0;
	while (p < n) {
		que q = pq.top(); pq.pop();
		res = q.t;
		p += q.p;
		pq.emplace(q.t+2*q.s, 4, q.s);
	}
	printf("%lld\n", res);
}
