#include <bits/stdc++.h>
using namespace std;

int c[200000];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", c+i);
	sort(c, c+n);
	double res = 1;
	for (int i = 0; i < n; i++)
		res = c[i] > i+1 ? -1 : min(res, c[i]/(i+1.0));
	if (res == -1)
		printf("impossible\n");
	else
		printf("%lf\n", res);
}
