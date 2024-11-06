#include <iostream>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m, ans = 0;
char board[50][51];
int dp[50][50];
bool visited[50][50];

int dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 'H') {
		return 0;
	}
	if (visited[x][y]) {
		cout << -1 << '\n';
		exit(0);
	}
	if (dp[x][y] != -1) 
		return dp[x][y];
	
	dp[x][y] = 0;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (board[x][y] - '0');
		int ny = y + dy[i] * (board[x][y] - '0');
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visited[x][y] = false;
	
	return dp[x][y];
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			dp[i][j] = -1;
		}
	}
	
	cout << dfs(0, 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
