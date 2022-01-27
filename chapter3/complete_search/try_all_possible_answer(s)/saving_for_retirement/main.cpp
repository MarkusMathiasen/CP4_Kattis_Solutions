#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, br, bs, a, as; scanf("%d%d%d%d%d", &b, &br, &bs, &a, &as);
	for (int ar = a; true; ar++)
		if ((ar-a)*as > (br-b)*bs) {
			printf("%d\n", ar);
			break;
		}
}
