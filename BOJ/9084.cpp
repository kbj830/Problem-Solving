#include <iostream>

#define endl "\n"

using namespace std;

int coins[22];
int dp[22][10001];

void clearArr() {
	for(int i = 0; i < 22; i++) {
		coins[i] = 0;
	}
	for(int j = 0; j < 22; j++) {
		for(int i = 0; i < 10001; i++) {
			dp[j][i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		clearArr();
		
		for(int i = 0; i < n; i++) {
			cin >> coins[i + 1];
		}
		
		int m;
		cin >> m;
		
		for(int i = 0; i <= n; i++) dp[i][0] = 1;
		
		for(int j = 1; j <= n; j++) {
			for(int i = 1; i <= m; i++) {
				dp[j][i] = dp[j - 1][i];
				if (i - coins[j] >= 0) {
					dp[j][i] += dp[j][i-coins[j]];
				}
			}
		}
		cout << dp[n][m] << endl;
	}
}
