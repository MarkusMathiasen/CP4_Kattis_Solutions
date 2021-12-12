#include <bits/stdc++.h>
using namespace std;

int main() {
	int res = 0;
	vector<int> regs(8, 0);
	vector<int> siz = {2, 3, 5, 7, 11, 13, 17, 19};
	for (int i = 0; i < 8; i++)
		scanf("%d", &regs[i]);
	int prod = 1;
	for (int i = 0; i < 8; i++) {
		res += prod*(siz[i]-regs[i]);
		regs[i+1]++;
		prod *= siz[i];
	}
	printf("%d\n", res-1);
}
