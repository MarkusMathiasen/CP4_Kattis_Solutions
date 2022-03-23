#include <bits/stdc++.h>
using namespace std;

int N, H;
vector<int> down, up;

int binSearch(int h, vector<int>& A) {
	int low = 0, high = A.size();
	while (low < high) {
		int mid = (low+high)/2;
		if (A[mid] <= h)
			low = mid+1;
		else
			high = mid;
	}
	return A.size() - low;
}

int main() {
	scanf("%d%d", &N, &H);
	for (int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		i%2 ? up.push_back(x) : down.push_back(x);
	}
	sort(down.begin(), down.end());
	sort(up.begin(), up.end());
	int bestHit = N+1;
	int heights = 0;
	for (int h = 0; h < H; h++) {
		int hits = 0;
		hits += binSearch(h, down);
		hits += binSearch(H-h-1, up);
		if (hits < bestHit) {
			bestHit = hits;
			heights = 1;
		}
		else if (hits == bestHit)
			heights++;
	}
	printf("%d %d\n", bestHit, heights);
}
