#include<iostream>

using namespace std;


int dx[] = {-1, 1, 0, 0},
	dy[] = {0, 0, -1, 1};

int n, m;
int map[500][500];
int dp[500][500];

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1)
		return 1;
	
    if (dp[x][y] != -1) 
		return dp[x][y];
	
	dp[x][y] = 0;
	
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (map[nx][ny] < map[x][y])
				dp[x][y] += dfs(nx, ny);
		}
	}
    return dp[x][y];
}

void solve() {
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << dfs(0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
    solve();
    return 0;
}
