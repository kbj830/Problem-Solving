#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k; //ans = 0;
int w[101], v[101];
int dp[101][100001];


// 첫번째 코드 (시간초과)
/*
void fill(int idx, int left, int val) {
	if (idx == n - 1 || left == 0)
		return;
	for (int i = idx; i < n; i++) {
		if (w[i] <= left) {
			val += v[i];
			if (val > ans)
				ans = val;
			fill(i, left - w[i], val);
			val -= v[i];
		}
	}
}
*/

void fill() {
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (w[j] > i)
				dp[j][i] = dp[j - 1][i];
			else
				dp[j][i] = max(dp[j - 1][i - w[j]] + v[j],
							   dp[j - 1][i]);
		}
	}
}

void solve() {
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	
	fill();
	
	cout << dp[n][k] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
