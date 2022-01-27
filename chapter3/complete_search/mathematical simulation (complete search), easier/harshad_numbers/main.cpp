#include <bits/stdc++.h>
using namespace std;

bool harshad(int x) {
	int cp = x;
	int sum = 0;
	while (cp)
		sum += cp%10,
		cp /= 10;
	return !(x%sum);
}

int main() {
	int n; scanf("%d", &n);
	while (!harshad(n))
		n++;
	printf("%d\n", n);
}
