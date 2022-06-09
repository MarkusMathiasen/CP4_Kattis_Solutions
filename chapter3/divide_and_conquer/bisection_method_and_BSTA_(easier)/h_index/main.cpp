#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int A[N], n;

bool check(int h) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += A[i] >= h;
	return cnt >= h;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", A+i);
	int low = 0, high = 1e9;
	while (low < high) {
		int mid = (low + high)/2;
		if (check(mid))
			low = mid+1;
		else
			high = mid;
	}
	printf("%d\n", low-1);
}
