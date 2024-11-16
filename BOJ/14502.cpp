#include<iostream>
#include <queue>
#include <memory.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, ans = 0;
int map[8][8], tmp[8][8];
bool visited[8][8];

void copy(int tmp[8][8], int map[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}

bool inRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
	int nmap[8][8];
	copy(nmap, tmp);
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (nmap[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (inRange(nx, ny) && !nmap[nx][ny]) {
				nmap[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j=0; j < m; j++) {
			if (!nmap[i][j]) {
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
}

void wall(int cur) {
	if (cur == 3) {
		bfs();
		return;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!tmp[i][j]) {
				tmp[i][j] = 1;
				wall(cur + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				memset(visited, 0, sizeof(visited));
				copy(tmp, map);
				tmp[i][j] = 1;
				wall(1);
				tmp[i][j] = 0;
			}
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}