#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		for (char& c : s)
			c = tolower(c);
		printf("%s\n", s.find("problem") == string::npos ? "no" : "yes");
	}
}
