#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll N;

void ask(string s) {
	printf("%s\n", s.c_str());
	fflush(stdout);
}
pii read() {
	ll s, e; cin >> s >> e;
	return {s, e};
}

void goal_h() {ask("ASK GABBY");}
void goal_t() {ask("ASK SPIKE");}

pii next_h() {
	ask("NEXT GABBY");
	pii res = read();
	if (res.first == 0) {
		goal_h();
		exit(EXIT_SUCCESS);
	}
	return res;
}
pii next_t() {
	ask("NEXT SPIKE");
	pii res = read();
	if (res.first == 0) {
		goal_t();
		exit(EXIT_SUCCESS);
	}
	return res;
}
pii return_h() {return ask("RETURN GABBY"), read();}
pii return_t() {return ask("RETURN SPIKE"), read();}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	ll e = 0, lam = 0, steps = 0;
	while (!e) {
		steps++;
		next_h(); next_h();
		auto [s,e2] = next_t();
		e = e2;
	}
	e = 0;
	while (!e) {
		lam++;
		e = next_t().second;
	}
	rep(i, 0, (N-steps)%lam) next_t();
	goal_t();
}
