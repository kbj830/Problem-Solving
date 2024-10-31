// 첫번째 코드 (시간초과)
/*
#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, ans;
bool maze[101][101];


#include <string>
void print(int x, int y) {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			string str;
			if (maze[j][i]) str = "□";
			else str = "●";
			cout << str;
		}
		cout << '\n';
	}
	
	string t;
	cin >> t;
}


bool inRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int findWay(int x, int y) {
	if (!inRange(x, y) || !maze[y][x])
		return n * m;
	
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	
	int dist = n * m;
	
	maze[y][x] = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		dist = min(dist, findWay(nx, ny));
	}
	maze[y][x] = true;
	
	return dist + 1;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			scanf("%1d", &temp);
			maze[j][i] = temp?true:false;
		}
	}
	cout <<findWay(0, 0) << '\n';
}

int main() {
	solve();
	return 0;
}
*/

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maze[101][101];
bool visited[101][101];
int dist[101][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int,int> > q;

void bfs(int ix, int iy) {
    visited[ix][iy] = 1;
    q.push(make_pair(ix, iy));
    dist[ix][iy]++;

    while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if ((nx >= 0 && nx < n && ny >= 0 && ny < m) && !visited[nx][ny] && maze[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	
	bfs(0, 0);

	cout << dist[n - 1][m - 1] << '\n';
}

int main() {
	solve();
	return 0;
}