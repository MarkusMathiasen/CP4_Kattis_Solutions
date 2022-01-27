#include <bits/stdc++.h>
using namespace std;

int digitSum(int x) {
	int res = 0;
	while (x)
		res += x%10,
		x /= 10;
	return res;
}

int main() {
	long long N;
	while (scanf("%lld", &N), N) {
		int sum = digitSum(N);
		for (long long i = 11; true; i++)
			if (digitSum(N*i) == sum) {
				printf("%lld\n", i);
				break;
			}
	}
}
