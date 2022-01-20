#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int x; scanf("%d", &x);
		int c = 0;
		for (c = 0; true; c++)
			if ((((1<<8)-1)&(c^(c << 1))) == x)
				break;
		printf("%d ", c);
	}
	printf("\n");
}
