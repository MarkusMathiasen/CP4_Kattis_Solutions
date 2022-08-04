#include <bits/stdc++.h>
using namespace std;

double L, K, T1, T2, H;

double amount(double fallen) {
	if (fallen <= L)
		return fallen;
	double leaktime = T1 + T2 - L*T1 / fallen;
	return max(L, fallen - leaktime*K);
}

int main() {
	scanf("%lf%lf%lf%lf%lf", &L, &K, &T1, &T2, &H);
	double low = 0, high = 1e9;
	while (low + 1e-8 < high) {
		double mid = (low + high)/2;
		if (amount(mid) + 1e-8 > H)
			high = mid;
		else
			low = mid;
	}
	printf("%lf ", low);
	low = 0, high = 1e9;
	while (low + 1e-8 < high) {
		double mid = (low + high)/2;
		if (amount(mid) - 1e-8 > H)
			high = mid;
		else
			low = mid;
	}
	printf("%lf\n", low);
}
