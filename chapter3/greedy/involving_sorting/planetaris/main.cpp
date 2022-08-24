#include <bits/stdc++.h>
using namespace std;

int e[100000];

int main() {
	int n, a; scanf("%d%d", &n, &a);
	for (int i = 0; i < n; i++)
		scanf("%d", e+i);
	sort(e, e+n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a <= e[i])
			break;
		res++;
		a -= e[i]+1;
	}
	printf("%d\n", res);
}
