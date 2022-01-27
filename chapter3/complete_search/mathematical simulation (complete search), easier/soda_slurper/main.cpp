#include <bits/stdc++.h>
using namespace std;

int main() {
	int e, f, c; scanf("%d%d%d", &e, &f, &c);
	int b = e+f;
	int res = 0;
	while (b >= c)
		b -= c-1,
		res++;
	printf("%d\n", res);
}
