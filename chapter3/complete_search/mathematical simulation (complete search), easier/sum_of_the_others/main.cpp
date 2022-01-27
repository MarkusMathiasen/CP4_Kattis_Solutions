#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while (getline(cin, s) && s != "") {
		stringstream ss(s);
		int sum = 0;
		int x;
		while (ss >> x)
			sum += x;
		printf("%d\n", sum/2);
	}
}
