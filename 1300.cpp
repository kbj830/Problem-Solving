#include <iostream>

using namespace std;

typedef long long ll;

ll ans;

void bin(ll n, ll k, ll lo, ll hi) {
	ll mid = (lo + hi) / 2, idx = 0;
	
	if (lo <= hi) {
		for (ll i = 1; i <= n; i++) {
			int temp = mid / i;
			if (temp > n)
				temp = n;
			idx += temp;
		}
		
		if (lo == hi) {
			ans = lo;
			return;
		}
		if (idx < k)
			bin(n, k, mid + 1, hi);
		else
			bin(n, k, lo, mid);
	}
}

void solve() {
	ll n, k;
	cin >> n >> k;
	
	bin(n, k, 1, n * n);
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}