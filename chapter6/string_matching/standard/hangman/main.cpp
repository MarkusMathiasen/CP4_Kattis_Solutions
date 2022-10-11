#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b; cin >> a >> b;
	set<char> remaining;
	for (char c : a)
		remaining.insert(c);
	int wrong = 0;
	for (char c : b) {
		if (remaining.empty())
			break;
		if (remaining.count(c))
			remaining.erase(c);
		else
			wrong++;
	}
	printf("%s\n", wrong < 10 ? "WIN" : "LOSE");
}
