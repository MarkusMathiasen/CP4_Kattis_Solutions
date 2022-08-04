#include <bits/stdc++.h>
using namespace std;

bool isMember(int x) {
	unordered_set<int> seen;
	while (!seen.count(x)) {
		seen.insert(x);
		x *= 3;
		if (x / 1000000 == 1)
			return false;
		x %= 1000000;
	}
	return true;
}

int main() {
	string line;
	while (cin >> line, line != "END") {
		if (line == "1" || line == "0") {
			printf("MEMBER\n");
			continue;
		}
		while (line.size() < 8)
			line.push_back('0');
		int x = stoi(line.substr(2));
		if (isMember(x))
			printf("MEMBER\n");
		else
			printf("NON-MEMBER\n");
	}
}
