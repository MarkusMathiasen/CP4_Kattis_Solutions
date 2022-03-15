#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int k, n; scanf("%d%d", &k, &n);
	vector<ii> hands(n, ii(3, 0));
	for (int i = 0; i < n; i++)
		hands[i].second = i+1;
	int idx = 0;
	while (n > 1) {
		idx = (idx+k-1)%n;
		if (--hands[idx].first == 2)
			hands.insert(hands.begin()+idx, ii(2, hands[idx].second)), n++;
		else if (hands[idx].first == 0)
			hands.erase(hands.begin()+idx), n--;
		else
			idx++;
		idx %= n;
	}
	printf("%d\n", hands[0].second);
}
