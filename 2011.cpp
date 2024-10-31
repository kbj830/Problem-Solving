#include <iostream>
#include <string>

#define MOD 1000000

using namespace std;

int dp[5001];

void solve() {
	string str;
	cin >> str;
	
	
	if (str[0] == '0') {
		cout << "0\n";
		return;
	}
	
	int l = str.length();
	dp[0] = 1;
	for (int i = 1; i < l; i++) {
		if (str[i] - '0')
			dp[i] = dp[i - 1];
		
		int tmp = (str[i - 1] - '0') * 10 + (str[i] - '0');
		if (tmp >= 10 && tmp <= 26) {
			if (i < 2)
				dp[i] = (dp[i] + 1) % MOD;
			else
				dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}
	
	cout << dp[l - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}