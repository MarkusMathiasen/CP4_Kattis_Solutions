#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int n, low, high;

int dist(int name) {
	int res = 2e9;
	for (int x : A)
		res = min(res, abs(x-name));
	return res;
}

int main() {
	scanf("%d", &n);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	scanf("%d%d", &low, &high);
	low += (low%2 == 0);
	high -= (high%2 == 0);
	vector<int> solutions = {low, high};
	for (int i = 0; i < n-1; i++) {
		int mid = (A[i] + A[i+1])/2;
		if (mid%2)
			solutions.push_back(mid);
		else
			solutions.push_back(mid+1),
			solutions.push_back(mid-1);
	}
	int name = -1, d = -1;
	for (int x : solutions) {
		if (x < low || x > high || dist(x) <= d)
			continue;
		d = dist(x);
		name = x;
	}
	printf("%d\n", name);
}
