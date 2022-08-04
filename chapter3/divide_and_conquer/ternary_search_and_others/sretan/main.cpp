#include <bits/stdc++.h>
using namespace std;

int main() {
	int k; scanf("%d", &k);
	int len = 31 - __builtin_clz(k+1);
	int under = (1 << len)-2;
	k -= under+1;
	for (int i = len-1; i >= 0; i--)
		printf(k & (1<<i) ? "7" : "4");
	printf("\n");
}
