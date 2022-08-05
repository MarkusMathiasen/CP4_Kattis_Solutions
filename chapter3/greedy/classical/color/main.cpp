#include <bits/stdc++.h>
using namespace std;

int socks[100000];

int main() {
	int s, c, k; scanf("%d%d%d", &s, &c, &k);
	for (int i = 0; i < s; i++)
		scanf("%d", socks+i);
	sort(socks, socks+s);
	int color = socks[0];
	int cnt = 0, res = 1;
	for (int i = 0; i < s; i++) {
		if (socks[i]-color > k || cnt == c)
			color = socks[i],
			cnt = 0,
			res++;
		cnt++;
	}
	printf("%d\n", res);
}
