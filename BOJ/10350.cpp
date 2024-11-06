#include <iostream>
#include <vector>
#include <math.h>

#define endl '\n'

typedef long long ll;

using namespace std;

ll n;
vector<ll> k;
vector<ll> s(1, 0);

void solve() {
	cin >> n;
	
	k.resize(n);
	
	for (ll i = 0; i < n; i++) {
		cin >> k[i];
	}
	
	for (ll i = 0; i < n * 2; i++) {
		s.push_back(s.back() + k[i % n]);
	}
	
	ll res = 0;
	
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 1; j <= n; j++) {
			if (s[i + j] < s[j - 1]) {
				res += ceil((double)abs(s[i + j] - s[j - 1]) / s[n]);
			}
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
