#include <iostream>

#define MOD 1000000000

typedef long long ll;
using namespace std;

ll dp[1000001];

void solve() {
	ll n;
	cin >> n;
	
	dp[1] = 0;
	dp[2] = 1;
	
	for (int i = 3; i <= n; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1) % MOD;
	
	cout << dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}