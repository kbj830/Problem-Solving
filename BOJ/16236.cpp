#include <iostream>
#include <queue>
 
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, bx, by, res = 0, count = 0, s = 2;
int map[22][22];
bool stop, eat;

void bfs(int a, int b, bool visit[][22], int shSize) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(a, b), 0));
	visit[b][a] = true;
	int temp;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		
		if (map[y][x] > 0 && map[y][x] < shSize && temp == cnt) {
			if (by > y || (by == y && bx > x)) {
				by = y;
				bx = x;
				continue;
			}
		}
		
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[ny][nx]) {
				if (map[ny][nx] <= shSize) {
					if (map[ny][nx] > 0 && map[ny][nx] < shSize && !eat) {
						eat = true;
						bx = nx;
						by = ny;
						temp = cnt + 1;
						res += temp;
					}
					else {
						q.push(make_pair(make_pair(nx, ny), cnt + 1));
						visit[ny][nx] = true;
					}
				}
			}
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == 9) {
				by = i;
				bx = j;
				map[i][j] = 0;
			}
		}
	}
	
	while (!stop) {
		bool visit[22][22] = {0};
		bfs(bx, by, visit, s);
		if (eat) {
			eat = false;
			count += 1;
			map[by][bx] = 0;
			
			if (count == s) {
				s += 1;
				count = 0;
			}
		}
		else {
			stop = true;
		}
	}
	
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
    return 0;
}
