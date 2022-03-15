#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int n; scanf("%d", &n);
	vector<ii> people(n, ii(0, 0));
	for (int i = 0; i < n; i++)
		scanf("%d", &people[i].first),
		people[i].second = i+1;
	int idx = 0;
	while (n > 1) {
		idx = (idx+people[idx].first-1)%n--;
		people.erase(people.begin()+idx);
		idx %= n;
	}
	printf("%d\n", people[0].second);
}
