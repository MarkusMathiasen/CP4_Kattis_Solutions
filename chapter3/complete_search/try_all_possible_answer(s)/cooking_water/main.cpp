#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int N; scanf("%d", &N);
	vector<ii> A(N, ii());
	for (int i = 0; i < N; i++)
		scanf("%d%d", &A[i].first, &A[i].second);
	int res = false;
	for (int t = 0; t <= 1000; t++) {
		int found = false;
		for (int i = 0; i < N && !found; i++)
			found |= A[i].first > t || A[i].second < t;
		res |= !found;
	}
	printf(res ? "gunilla has a point\n" : "edward is right\n");
}
