#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int x = 0, total = 0;
	while (cin >> s) {
		total++;
		x += s.find("ae") != string::npos;
	}
	if (x*5 >= total*2)
		printf("dae ae ju traeligt va\n");
	else
		printf("haer talar vi rikssvenska\n");
}
