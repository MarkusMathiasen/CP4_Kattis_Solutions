#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

ii s[30];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i].first),
		s[i].second = i+1;
	sort(s, s+n, greater<>());
	int postsum = 0;
	for (int i = 1; i < n; i++)
		postsum += s[i].first;
	if (s[0].first > postsum)
		printf("impossible");
	else
		for (int i = 0; i < n; i++)
			printf("%d ", s[i].second);
	printf("\n");
}
