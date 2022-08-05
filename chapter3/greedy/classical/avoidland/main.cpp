#include <bits/stdc++.h>
using namespace std;

struct pawn {
	int x, y;
};
pawn pawns[1000000];

int main() {
	int n; scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &pawns[i].x, &pawns[i].y);
	sort(pawns, pawns+n, [](const pawn& a, const pawn& b) {
		return a.x < b.x;
	});
	for (int i = 1; i <= n; i++)
		res += abs(pawns[i-1].x - i);
	sort (pawns, pawns+n, [](const pawn& a, const pawn& b) {
		return a.y < b.y;
	});
	for (int i = 1; i <= n; i++)
		res += abs(pawns[i-1].y - i);
	printf("%d\n", res);
}
