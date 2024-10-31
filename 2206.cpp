#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1},
	dy[4] = {1, 0, -1, 0};

int n, m;
int map[1001][1001][2];
bool visited[1001][1001];

int move() {
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {0, 0}});
	
	while(!q.empty()) {
		int b = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		
		if (x == n - 1 && y == m - 1) 
			return map[n - 1][m - 1][b] + 1;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;
			if (map[nx][ny][0] == 1) {
				if (!b) {
					map[nx][ny][b + 1] = map[x][y][b] + 1;
					q.push({1, {nx, ny}});
				}
			}
			else if (map[nx][ny][0] == 0) {
				if (b == 1 && map[nx][ny][b])
					continue;
				map[nx][ny][b] = map[x][y][b] + 1;
				q.push({b, {nx, ny}});
			}
		}
	}
	return -1;
}

void solve() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp;
			cin >> tmp;
			map[i][j][0] = tmp - '0';
		}
	}
	
	cout << move() << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}