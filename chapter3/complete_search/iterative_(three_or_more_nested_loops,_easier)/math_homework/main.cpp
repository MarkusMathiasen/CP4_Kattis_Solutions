#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, l; scanf("%d%d%d%d", &a, &b, &c, &l);
	bool found = false;
	for (int i = 0; i*a <= l; i++)
		for (int j = 0; i*a+j*b <= l; j++)
			if ((l - i*a-j*b)%c == 0)
				printf("%d %d %d\n", i, j, (l-i*a-j*b)/c),
				found = true;
	if (!found)
		printf("impossible\n");
}
