#include <bits/stdc++.h>
using namespace std;

struct minion {
	int L, U;
	bool operator<(const minion& a) const {
		return U < a.U;
	}
};

int main() {
	int N; scanf("%d", &N);
	vector<minion> A(N, minion());
	for (int i = 0; i < N; i++)
		scanf("%d%d", &A[i].L, &A[i].U);
	sort(A.begin(), A.end());
	int res = 0;
	int val = -10;
	for (minion& m : A)
		if (m.L > val)
			res++, val = m.U;
	printf("%d\n", res);
}
