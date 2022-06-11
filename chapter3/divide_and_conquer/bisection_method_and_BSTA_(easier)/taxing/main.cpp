#include <bits/stdc++.h>
using namespace std;

struct band {
	double s;
	double p;
};
struct person {
	double e;
	double m;
};

int B, F;
double P;
vector<band> bands;
vector<person> persons;

double tax(double money) {
	double rem = 0;
	for (int i = 0; i < B; i++) {
		double am = min(bands[i].s, money);
		rem += am*(1-bands[i].p);
		money -= am;
	}
	rem += money*(1-P);
	return rem;
}

int main() {
	scanf("%d", &B);
	bands.assign(B, band());
	for (int i = 0; i < B; i++)
		scanf("%lf%lf", &bands[i].s, &bands[i].p),
		bands[i].p /= 100;
	scanf("%lf%d", &P, &F); P /= 100;
	persons.assign(F, person());
	for (int i = 0; i < F; i++)
		scanf("%lf%lf", &persons[i].e, &persons[i].m);
	for (int f = 0; f < F; f++) {
			double low = 0, high = 1e12;
		while (low + 1e-7 < high && low + low * 1e-7 < high) {
			double mid = (low + high)/2;
			if (tax(persons[f].e + mid) < tax(persons[f].e) + persons[f].m)
				low = mid;
			else
				high = mid;
		}
		printf("%lf\n", low);
	}
}
