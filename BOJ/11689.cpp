#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	
	ll ans = n;
	
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0)
				n /= i;
		}
	}
	
	if (n > 1)
		ans -= ans / n;
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solve();
}
