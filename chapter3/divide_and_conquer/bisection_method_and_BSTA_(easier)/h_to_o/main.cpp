#include <bits/stdc++.h>
using namespace std;

int ins[26], outs[26];

void readMolecule(int* a) {
	for (int i = 0; i < 26; i++)
		a[i] = 0;
	char c;
	char prev = 'A';
	int n = -1;
	while (scanf("%c", &c) != EOF && c != '\n' && c != ' ') {
		if (isdigit(c)) {
			if (n == 0)
				n = c - '0';
			else
				n = 10*n + c - '0';
		}
		else {
			if (n != -1)
				a[prev-'A'] += max(1, n);
			n = 0;
			prev = c;
		}
	}
	a[prev-'A'] += max(1, n);
}

int main() {
	readMolecule(ins);
	int k; scanf("%d\n", &k);
	readMolecule(outs);
	int res = 1e9;
	for (int i = 0; i < 26; i++)
		if (outs[i] != 0)
			res = min(res, (ins[i]*k)/outs[i]);
	printf("%d\n", res);
}
