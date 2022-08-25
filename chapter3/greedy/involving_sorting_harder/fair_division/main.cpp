#include <bits/stdc++.h>
using namespace std;

struct person {
	int a, i, p;
};

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int p, n; scanf("%d%d", &p, &n);
		vector<person> A(n, person());
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i].a),
			A[i].i = i;
		sort(A.begin(), A.end(), [](const person& a, const person& b){
			if (a.a != b.a)
				return a.a < b.a;
			return a.i > b.i;
		});
		for (int i = 0; i < n; i++) {
			A[i].p = min(A[i].a, p/(n-i));
			p -= A[i].p;
		}
		sort(A.begin(), A.end(), [](const person& a, const person& b) {
			return a.i < b.i;
		});
		if (p)
			printf("IMPOSSIBLE");
		else
			for (person& x : A)
				printf("%d ", x.p);
		printf("\n");
	}
}
