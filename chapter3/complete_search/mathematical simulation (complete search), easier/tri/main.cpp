#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	string res;
	if (a+b == c)
		res = "+=";
	if (a-b == c)
		res = "-=";
	if (a*b == c)
		res = "*=";
	if (a/b == c && a%b == 0)
		res = "/=";
	if (a == b+c)
		res = "=+";
	if (a == b-c)
		res = "=-";
	if (a == b*c)
		res = "=*";
	if (a == b/c && b%c == 0)
		res = "=/";
	printf("%d%c%d%c%d\n", a, res[0], b, res[1], c);
}
