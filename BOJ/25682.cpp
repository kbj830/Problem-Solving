#include <iostream>

using namespace std;

int n, m, k, ans = 1e9;
int board[2001][2001];

void solve() {
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp;
			cin >> tmp;
			if (((i + j) % 2 && tmp == 'B') || ((i + j) % 2 == 0 && tmp != 'B')) 
				board[i][j] = 1;
			board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];
		}
	}
	
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			int repaint = board[i][j] - board[i - k][j] - board[i][j - k] + board[i - k][j - k];
			repaint = min(k * k - repaint, repaint);
			ans = min(repaint, ans);
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
