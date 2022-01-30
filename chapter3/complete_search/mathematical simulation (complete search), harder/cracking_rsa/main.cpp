#include <bits/stdc++.h>
using namespace std;

int main() {
	long long T; scanf("%lld", &T);
	while (T--) {
		long long n, e; scanf("%lld%lld", &n, &e);
		long long p = -1, q = -1;
		for (long long i = 2; true; i++)
			if (n%i == 0) {
				p = i;
				q = n/i;
				break;
			}
		long long phi = (p-1)*(q-1);
		for (long long d = 2; d < phi; d++) {
			if ((d*e)%phi == 1) {
				printf("%lld\n", d);
				break;
			}
		}
	}
}
