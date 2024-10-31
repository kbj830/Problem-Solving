#include <iostream>

#define endl '\n'
#define MOD 1000000007

using ll = long long;

using namespace std;

ll fac[4000001];

ll power(ll x, ll n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n % 2)
		return ((power(x, n - 1) % MOD) * x) % MOD;
	ll k = power(x, n / 2);
	return ((k % MOD) * (k % MOD)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll m, n, k;
	cin >> m;
	
	fac[0] = 1;
	
	for(ll i = 1; i <= 4000000; i++) {
		fac[i] = ((fac[i - 1] % MOD) * i) % MOD;
	}
	
	while(m--) {
		cin >> n >> k;
		cout << (fac[n] * power((fac[k] * fac[n - k]) % MOD, MOD - 2)) % MOD << endl;
	}
	
	
}