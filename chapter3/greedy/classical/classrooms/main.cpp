#include <bits/stdc++.h>
using namespace std;

struct activity {
	int s, f;
};
bool operator<(const activity& a, const activity& b) {
	return tie(a.f, a.s) < tie(b.f, b.s);
}

activity activities[200000];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &activities[i].s, &activities[i].f);
	sort(activities, activities+n);
	multiset<int> rooms;
	for (int i = 0; i < k; i++)
		rooms.insert(0);
	int res = 0;
	for (int i = 0; i < n; i++)
		if (*rooms.begin() < activities[i].s)
			rooms.erase(--rooms.lower_bound(activities[i].s)),
			rooms.insert(activities[i].f),
			res++;
	printf("%d\n", res);
}
