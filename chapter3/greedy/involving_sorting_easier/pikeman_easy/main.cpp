#include <bits/stdc++.h>
using namespace std;

long long t[10000];

int main() {
	long long N, T; scanf("%lld%lld", &N, &T);
	long long A, B, C, t0; scanf("%lld%lld%lld%lld", &A, &B, &C, &t0);
	t[0] = t0;
	for (long long i = 1; i < N; i++)
		t[i] = ((A*t[i-1]+B)%C)+1;
	sort(t, t+N);
	long long tim = 0;
	long long solved = 0, penalty = 0;
	for (int i = 0; i < N; i++) {
		if (tim + t[i] > T)
			break;
		solved++;
		tim += t[i];
		penalty = (penalty + tim) % 1000000007;
	}
	printf("%lld %lld\n", solved, penalty);
}
