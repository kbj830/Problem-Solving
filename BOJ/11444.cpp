#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

#define MOD 1000000007

map<ll, ll> f;

ll fib(ll n) {
	if (n == 0) 
		return 0;
	if (n == 1 || n == 2) 
		return 1;
	if (f.count(n))
		return f[n];
	
	if (n % 2 == 0) {
		ll m = n / 2;
		ll tmp1 = fib(m - 1);
		ll tmp2 = fib(m);
		f[n] = ((2 * tmp1 + tmp2) * tmp2) % MOD;
		return f[n];
	}
	
	ll m = (n + 1) / 2;
	ll tmp1 = fib(m);
	ll tmp2 = fib(m - 1);
	f[n] = (tmp1 * tmp1 + tmp2 * tmp2) % MOD;
	return f[n];
}

void solve() {
	ll n;
	cin >> n;
	cout << fib(n) << '\n';
}

int main() {
	solve();
	return 0;
}
