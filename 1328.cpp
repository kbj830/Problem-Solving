#include <iostream>

#define endl '\n'
#define MOD 1000000007

using namespace std;

long long dp[101][101][101];

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	
	dp[1][1][1] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[i][j][k] = (dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k] * (i-2)) % MOD;
			}
		}
	}
	
	cout << dp[n][l][r] << endl;
}