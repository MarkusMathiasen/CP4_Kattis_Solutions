#include <bits/stdc++.h>
using namespace std;

int main() {
	long long D; scanf("%lld", &D);
	for (long long n1 = 0; n1 <= D/2; n1++) {
		long long n2 = round(sqrt(D+n1*n1));
		if (n2*n2 == D+n1*n1) {
			printf("%lld %lld\n", n1, n2);
			return 0;
		}
	}
	printf("impossible\n");
}
