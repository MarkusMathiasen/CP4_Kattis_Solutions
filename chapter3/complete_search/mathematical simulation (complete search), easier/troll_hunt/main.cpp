#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, k, g; scanf("%d%d%d", &b, &k, &g); b--;
	printf("%d\n", b/(k/g) + (b%(k/g) > 0));
}
