#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		int num = 1;
		for (int i = 1; i <= N; i++)
			num *= i;
		printf("%d\n", num%10);
	}
}
