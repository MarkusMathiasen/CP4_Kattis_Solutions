#include <bits/stdc++.h>
using namespace std;

struct call {
	int source;
	int destination;
	int start;
	int duration;
};

int N, M;
vector<call> calls;

int main() {
	while (scanf("%d%d", &N, &M) != EOF) {
		calls.assign(N, call());
		for (int i = 0; i < N; i++)
			scanf("%d%d%d%d", &calls[i].source, &calls[i].destination, &calls[i].start, &calls[i].duration);
		while (M--) {
			int res = 0;
			int start, duration; scanf("%d%d", &start, &duration);
			for (call& c : calls)
				res += start + duration > c.start && start < c.start + c.duration;
			printf("%d\n", res);
		}
	}
}
