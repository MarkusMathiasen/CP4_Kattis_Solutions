#include <bits/stdc++.h>
using namespace std;

int sumTo[60];
int res[100001];
int T;

int sum(int x) {
	int res = 0;
	while (x) {
		res += x%10;
		x /= 10;
	}
	return res;
}

int main() {
	sumTo[0] = 0;
	for (int i = 1; i <= 100000; i++) {
		int s = sum(i);
		res[i] = sumTo[s-1];
		sumTo[s] = i;
	}
	scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		printf("%d\n", res[x]);
	}
}
