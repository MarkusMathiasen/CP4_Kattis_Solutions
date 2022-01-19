#include <bits/stdc++.h>
using namespace std;

struct day {
	int d;
	int m;
	int y;
	const bool operator< (const day& a) const {
		if (y != a.y)
			return y < a.y;
		if (m != a.m)
			return m < a.m;
		return d < a.d;
	}
};

day getDay(string& s) {
	day res;
	res.d = stoi(s.substr(0, 2));
	res.m = stoi(s.substr(2, 2));
	res.y = stoi(s.substr(4, 4));
	return res;
}


vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool valid(day& d) {
	if (d.y < 2000 || d.d < 1 || 12 < d.m || d.m < 1)
		return false;
	if (d.m != 2)
		return d.d <= months[d.m];
	if (d.y%400 == 0 ||
		d.y%100 != 0 && d.y%4 == 0)
		return d.d <= 29;
	return d.d <= 28;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string a, b, c; cin >> a >> b >> c;
		string s = a + b + c;
		sort(s.begin(), s.end());
		vector<day> days;
		do {
			day d = getDay(s);
			if (valid(d))
				days.push_back(d);
		} while(next_permutation(s.begin(), s.end()));
		sort(days.begin(), days.end());
		if (days.size())
			printf("%ld %02d %02d %d\n", days.size(), days[0].d, days[0].m, days[0].y);
		else
			printf("0\n");
	}
}
