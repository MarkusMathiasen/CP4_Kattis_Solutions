#include <bits/stdc++.h>
using namespace std;

int main() {
	int d, s; scanf("%d%d", &d, &s);
	double low = 0, high = 1e18;
	while (low < high - 1e-10) {
		double a = (low + high)/2;
		if (a + s < a * cosh(d / (2*a)))
			low = a;
		else
			high = a;
	}
	printf("%lf\n", 2*low*sinh(d / (2*low)));
}
