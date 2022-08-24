#include <bits/stdc++.h>
using namespace std;

struct ant {
	int pos;
	bool left;
	bool operator<(const ant& other) const {
		return pos < other.pos;
	}
};

int main() {
	int L, A;
	while (scanf("%d%d", &L, &A) != EOF) {
		int l = -1, r = L+1;
		vector<ant> ants(A, ant());
		for (int i = 0; i < A; i++) {
			char c; scanf("%d %c", &ants[i].pos, &c);
			ants[i].left = c == 'L';
			if (ants[i].left)
				l = max(l, ants[i].pos);
			else
				r = min(r, ants[i].pos);
		}
		printf("The last ant will fall down in %d seconds - started at ", max(l, L-r));
		sort(ants.begin(), ants.end());
		int last_left = -1;
		queue<int> going_right;
		for (ant& a : ants) {
			if (!a.left)
				going_right.push(a.pos);
			else if (going_right.empty()) // ant is going left in the remaining cases
				last_left = a.pos;
			else
				last_left = going_right.front(),
				going_right.pop(),
				going_right.push(a.pos);
		}
		if (l == L-r)
			printf("%d and %d.\n", min(last_left, going_right.front()), max(last_left, going_right.front()));
		else
			printf("%d.\n", l > L-r ? last_left : going_right.front());
	}
}
