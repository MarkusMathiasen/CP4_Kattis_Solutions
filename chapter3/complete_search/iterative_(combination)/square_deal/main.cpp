#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int main() {
	bool res = false;
	ii rects[3];
	for (int i = 0; i < 3; i++)
		scanf("%d%d", &rects[i].first, &rects[i].second);
	for (int rot = 0; rot < (1<<3); rot++) {
		ii rec[3];
		for (int i = 0; i < 3; i++) {
			rec[i] = rects[i];
			if (rot & (1<<i))
				swap(rec[i].first, rec[i].second);
		}
		sort(rec, rec+3);
		do {
			res |= rec[0].first == rec[1].first
				&& rec[1].first == rec[2].first
				&& rec[0].first == rec[0].second+rec[1].second+rec[2].second;
			res |= rec[0].first == rec[1].first
				&& rec[0].second+rec[1].second == rec[2].second
				&& rec[0].first+rec[2].first == rec[2].second;
		} while(next_permutation(rec, rec+3));
	}
	printf(res ? "YES\n" : "NO\n");
}
