#include <bits/stdc++.h>
using namespace std;

int w, h;

double cost(double x) {
	double res = 0;
	double xh = h * x / w;
	res -= xh*xh/2;
	res += (xh+x)*(xh+x)/4;
	res += (xh+w-x+h)*(xh+w-x+h)/4;
	return res;
}

int main() {
	printf("provide w, h: ");
	scanf("%d%d", &w, &h);
	double low = 0.001, high = w-0.001;
	while (low + 1e-8 < high) {
		double d = (high - low)/3;
		if (cost(low + d) < cost(high - d))
			high -= d;
		else
			low += d;
	}
	printf("cost = %lf\n", cost(low));
	printf("pos  = %lf\n", low);
}
