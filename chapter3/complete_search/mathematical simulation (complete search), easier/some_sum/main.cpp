#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	if (n%2)
		printf("Either\n");
	else
		printf((n/2)%2 ? "Odd\n" : "Even\n");
}
