#include <bits/stdc++.h>
using namespace std;

int n;
double p, s, v;

double computer_time(double c) {
	double po = pow(log2(n), c*sqrt(2));
	double top = ((double)n) * po;
	double bot = p * 1e9;
	return top / bot;
}
double flight_time(double c) {
	return s * (1 + 1/c) / v;
}
double total_time(double c) {
	double ct = computer_time(c);
	double ft = flight_time(c);
	return ct + ft;
}

int main() {
	scanf("%d%lf%lf%lf", &n, &p, &s, &v);
	double low = 1e-20, high = 1e2;
	while (low + 1e-8 < high && low * (1 + 1e-8) < high) {
		double d = (high-low)/3;
		double t1 = total_time(low+d);
		double t2 = total_time(high-d);
		if (t1 < t2)
			high -= d;
		else
			low += d;
	}
	printf("%lf %lf\n", total_time(low), low);
}
