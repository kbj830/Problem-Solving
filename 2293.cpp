#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[101], dp[10001];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int c = coin[i];
		for (int j = c; j <= k; j++) 
			dp[j] += dp[j - c];
	}
	
	cout << dp[k] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
