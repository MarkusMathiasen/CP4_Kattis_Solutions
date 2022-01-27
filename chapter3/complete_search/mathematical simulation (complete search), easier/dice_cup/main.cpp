#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b; scanf("%d%d", &a, &b);
	if (a > b)
		swap(a, b);
	for (int i = a+1; i <= b+1; i++)
		printf("%d\n", i);
}
