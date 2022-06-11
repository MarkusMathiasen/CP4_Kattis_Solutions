#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 100;

ll T, N, M;
ll A[maxN], B[maxN], C[maxN], D[maxN];

ll cracked(ll t, ll* A, ll* B, int siz) {
	ll res = 0;
	for (int i = 0; i < siz; i++)
		res += max((t-A[i])/B[i], 0ll) + (t >= A[i]);
	return res;
}

ll tim(ll c, ll* A, ll* B, int siz) {
	ll low = 0, high = 1e9;
	while (low < high) {
		ll mid = (low + high)/2;
		if (cracked(mid, A, B, siz) < c)
			low = mid+1;
		else
			high = mid;
	}
	return low;
}

int main() {
	scanf("%lld%lld", &T, &N);
	for (int i = 0; i < N; i++)
		scanf("%lld%lld", A+i, B+i);
	scanf("%lld", &M);
	for (int i = 0; i < M; i++)
		scanf("%lld%lld", C+i, D+i);
	ll low = 0, high = 1e9;
	while (low < high) {
		ll mid = (low + high)/2;
		ll ta = tim(mid, A, B, N);
		ll tb = tim(mid, C, D, M);
		if (ta + tb < T)
			low = mid+1;
		else
			high = mid;
	}
	printf("%lld\n", tim(low, A, B, N));
}
