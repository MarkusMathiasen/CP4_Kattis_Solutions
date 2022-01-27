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
	int L, D, X; scanf("%d%d%d", &L, &D, &X);
	for (int i = L; true; i++)
		if (digitSum(i) == X) {
			printf("%d\n", i);
			break;
		}
	for (int i = D; true; i--)
		if (digitSum(i) == X) {
			printf("%d\n", i);
			break;
		}
}
