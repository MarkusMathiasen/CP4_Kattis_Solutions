#include <bits/stdc++.h>
using namespace std;

int main() {
	double x; int y1, y2; scanf("%lf%d%d", &x, &y1, &y2);
	int k = 0;
	while (ceil(x) < y1)
		k++,
		x = 10*sqrt(x);
	if (ceil(x) > y2) {
		printf("impossible\n");
		return 0;
	}
	printf("%d ", k);
	if (y2 == 100) {
		printf("inf\n");
		return 0;
	}
	while (ceil(x) <= y2)
		k++,
		x = 10*sqrt(x);
	printf("%d\n", k-1);
}
