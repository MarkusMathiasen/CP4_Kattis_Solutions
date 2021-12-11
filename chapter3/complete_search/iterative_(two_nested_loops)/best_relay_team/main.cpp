#include <bits/stdc++.h>
using namespace std;

struct runner {
	double t1, t2;
	string name;
	bool operator==(const runner& a) const {
		return name == a.name;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<runner> A(n, runner());
	for (int i = 0; i < n; i++)
		cin >> A[i].name >> A[i].t1 >> A[i].t2;
	sort(A.begin(), A.end(), [](const runner& a, const runner& b) {
		return a.t1 < b.t1;
	});
	vector<runner> A1(A.begin(), A.begin()+4);
	sort(A.begin(), A.end(), [](const runner& a, const runner& b) {
		return a.t2 < b.t2;
	});
	vector<runner> A2(A.begin(), A.begin()+4);
	double bestTim = 1e9;
	vector<runner> team;
	for (int i = 0; i < 4; i++) {
		double tim = A1[i].t1;
		vector<runner> att = {A1[i]};
		for (int j = 0; j < 4; j++) {
			if (att[0] == A2[j] || att.size() == 4l)
				continue;
			att.push_back(A2[j]);
			tim += att.back().t2;
		}
		if (tim < bestTim) {
			bestTim = tim;
			team = att;
		}
	}
	printf("%lf\n", bestTim);
	for (runner& r : team)
		printf("%s\n", r.name.c_str());
}
