#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_DIST = 1e9;

int n;
vector<pii> stops;
vector<string> pokemon;
set<string> pokemons;
vector<vi> dp;
vector<int> poke_bits;

int dist(int a, int b) {
	return abs(stops[a].first - stops[b].first)
			+ abs(stops[a].second - stops[b].second);
}

bool is_valid(int mask) {
	// TODO: check if mask is valid solution
	set<string> found_pokemon;
	for (int poke_bit : poke_bits)
		if (!(poke_bit & mask))
			return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n; n++;
	stops.assign(n, pii(0, 0));
	pokemon.assign(n, "");
	rep(i, 1, n) {
		cin >> stops[i].first >> stops[i].second;
		cin >> pokemon[i];
		pokemons.insert(pokemon[i]);
	}
	// Setup poke_bits for quick verification of solution
	for (string poke : pokemons) {
		int poke_bit = 0;
		rep(i, 0, n)
			if (pokemon[i] == poke)
				poke_bit += 1 << i;
		poke_bits.push_back(poke_bit);
	}
	// TSP
	dp.assign(1 << n, vi(n, MAX_DIST));
	dp[1][0] = 0;
	int res = MAX_DIST;
	rep(mask, 0, 1<<n) rep(i, 0, n) {
		if (dp[mask][i] == MAX_DIST) // If unreachable position
			continue;
		if (is_valid(mask)) {
			res = min(res, dp[mask][i] + dist(i, 0));
			continue;
		}
		rep(j, 1, n) {
			if (mask & (1 << j)) // If already visited
				continue;
			int new_mask = mask | (1 << j);
			dp[new_mask][j] = min(dp[new_mask][j],
					dp[mask][i] + dist(i,j));
		}
	}
	printf("%d\n", res);
}
