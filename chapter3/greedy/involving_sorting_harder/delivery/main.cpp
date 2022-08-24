#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int N, K; 
int calc(vector<ii>& A) {
	int i = 0, res = 0;
	while (i < (int)A.size()) {
		res += 2*A[i].first;
		int k = K;
		while (k && i < (int)A.size()) {
			if (k >= A[i].second)
				k-= A[i++].second;
			else
				A[i].second -= k, k = 0;
		}
	}
	return res;
}

int main() {
	scanf("%d%d", &N, &K);
	vector<ii> neg, pos;
	for (int i = 0; i < N; i++) {
		int x, t; scanf("%d%d", &x, &t);
		if (x < 0)
			neg.push_back(ii(-x, t));
		else
			pos.emplace_back(x, t);
	}
	sort(pos.rbegin(), pos.rend());
	printf("%d\n", calc(neg) + calc(pos));
}
