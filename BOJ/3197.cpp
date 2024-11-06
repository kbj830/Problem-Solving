#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

#define MAX 1500

using namespace std;

int r, c, ans;
bool found = false;
char map[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> swanQ, swanNQ, Q, NQ;
pair<int, int> pos;

void Input() {
	
}

void swan() {
	while (swanQ.empty() == 0 && found == false) {
		int x = swanQ.front().first;
		int y = swanQ.front().second;
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				if (visit[nx][ny] == false) {
					if (map[nx][ny] == '.') {
						visit[nx][ny] = true;
						swanQ.push(make_pair(nx, ny));
					}
					else if (map[nx][ny] == 'L') {
						visit[nx][ny] = true;
						found = true;
						break;
					}
					else if (map[nx][ny] == 'X') {
						visit[nx][ny] = true;
						swanNQ.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

void water() {
	while (Q.empty() == 0) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				if (map[nx][ny] == 'X') {
					map[nx][ny] = '.';
					NQ.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void Solution() {
	
}

void Solve() {
	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			
			if (map[i][j] != 'X') 
				Q.push(make_pair(i, j));
			if (map[i][j] == 'L') {
				pos.first = i;
				pos.second = j;
			}
		}
	}
	
	swanQ.push(make_pair(pos.first, pos.second));
	visit[pos.first][pos.second] = true;
	
	while (found == false) {
		swan();
		if (found == false) {
			water();
			Q = NQ;
			swanQ = swanNQ;
			while (NQ.empty() == 0) 
				NQ.pop();
			while (swanNQ.empty() == 0) 
				swanNQ.pop();
			ans++;
		}
	}
	
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Solve();
	return 0;
}
