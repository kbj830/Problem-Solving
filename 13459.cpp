#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct INFO {
	int rx, ry, bx, by, cnt;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

INFO start;
char board[10][11];

int bfs() {
	int visited[10][10][10][10] = { 0, };
	queue<INFO> q;
	q.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = 1;

	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		
		if (cur.cnt > 10) 
			break;
		
		if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
			return 1;
		}
		
		for (int i = 0; i < 4; i++) {
			int nrx = cur.rx;
			int nry = cur.ry;
			int nbx = cur.bx;
			int nby = cur.by;
			
			while (true) {
				if (board[nrx][nry] != '#' && board[nrx][nry] != 'O') {
					nrx += dx[i];
					nry += dy[i];
				}
				else {
					if (board[nrx][nry] == '#') {
						nrx -= dx[i];
						nry -= dy[i];
					}
					break;
				}
			}
			
			while (true) {
				if (board[nbx][nby] != '#' && board[nbx][nby] != 'O') {
					nbx += dx[i];
					nby += dy[i];
				}
				else {
					if (board[nbx][nby] == '#') {
						nbx -= dx[i];
						nby -= dy[i];
					}
					break;
				}
			}
			
			if (nrx == nbx && nry == nby) {
				if (board[nrx][nry] != 'O') {
					int rdist = abs(nrx - cur.rx) + abs(nry - cur.ry);
					int bdist = abs(nbx - cur.bx) + abs(nby - cur.by);
					
					if (bdist > rdist) {
						nbx -= dx[i];
						nby -=dy[i];
					}
					else {
						nrx -= dx[i];
						nry -= dy[i];
					}
				}
			}
			
			if (visited[nrx][nry][nbx][nby] == 0) {
				INFO next;
				
				visited[nrx][nry][nbx][nby] = 1;
				
				next.rx = nrx;
				next.ry = nry;
				next.bx = nbx;
				next.by = nby;
				next.cnt = cur.cnt + 1;
				
				q.push(next);
			}
		}
	}
	
	return 0;
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			if (board[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
	}

	start.cnt = 0;

	int ans = bfs();
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}