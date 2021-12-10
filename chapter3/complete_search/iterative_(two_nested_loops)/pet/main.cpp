#include <bits/stdc++.h>
using namespace std;

int main() {
	int p = -1, s = -1;
	for (int i = 0; i < 5; i++) {
		int res = 0;
		for (int j = 0; j < 4; j++) {
			int x; scanf("%d", &x);
			res += x;
		}
		if (res > s)
			s = res,
			p = i+1;
	}
	printf("%d %d\n", p, s);
}
