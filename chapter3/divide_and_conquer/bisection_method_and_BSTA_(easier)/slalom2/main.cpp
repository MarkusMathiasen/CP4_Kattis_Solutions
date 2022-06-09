#include <bits/stdc++.h>
using namespace std;

struct gate {
	int x;
	int y;
};

int W, vh, N, S;
vector<gate> gates;
vector<int> speeds;

bool check(double s) {
	double left = gates[0].x, right = left + W;
	for (int i = 0; i < N-1; i++) {
		int dy = gates[i+1].y - gates[i].y;
		double dt = dy / s;
		right = min(right + dt*vh, (double)(gates[i+1].x + W));
		left = max(left - dt*vh, (double)gates[i+1].x);
		if (right < left)
			return false;
	}
	return true;
}

int main() {
	scanf("%d%d%d", &W, &vh, &N);
	gates.assign(N, gate());
	for (int i = 0; i < N; i++)
		scanf("%d%d", &gates[i].x, &gates[i].y);
	scanf("%d", &S);
	speeds.assign(S, 0);
	for (int i = 0; i < S; i++)
		scanf("%d", &speeds[i]);
	sort(speeds.begin(), speeds.end());
	int low = 0, high = S;
	while (low < high) {
		int mid = (low + high)/2;
		if (check(speeds[mid]))
			low = mid+1;
		else
			high = mid;
	}
	if (!low)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", speeds[low-1]);
}
