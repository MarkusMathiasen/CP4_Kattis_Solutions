#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		printf("0.");
		for (int i = 0; i < c; i++) {
			a *= 10;
			printf("%d", a/b);
			a %= b;
		}
		printf("\n");
	}
}
