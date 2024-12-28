#include <iostream>

using namespace std;

int n, m;
int map[1000][1000];
int dp[1000][1000][3];
bool visit[1000][1000];

int dx[] = {0, 0, 1};
int dy[] = {1, -1, 0};

int dfs(int x, int y, int dir) {
    if (x == n - 1 && y == m - 1) 
        return map[x][y];
    if (dp[x][y][dir] != -1e9) 
        return dp[x][y][dir];

    visit[x][y] = true;
    int mx = -1e9;
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (visit[nx][ny] == false) {
                mx = max(mx, dfs(nx, ny, i));
            }
        }
    }
    visit[x][y] = false;

    dp[x][y][dir] = map[x][y] + mx;

    return dp[x][y][dir];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = -1e9;
            }
        }
    }
    cout << dfs(0, 0, 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}

