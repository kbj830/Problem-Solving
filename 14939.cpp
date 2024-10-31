#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 10
#define INF 1e9

bool arr[15][15], tmpArr[15][15];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans = INF;

void toggle(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!(x < 0 || x >= MAX || y < 0 || y >= MAX))
			tmpArr[nx][ny] = !tmpArr[nx][ny];
	}
	tmpArr[x][y] = !tmpArr[x][y];
}

void init() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			tmpArr[i][j] = arr[i][j];
}

bool islight() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (tmpArr[i][j])
				return 1;
		}
	}
	
	return 0;
}

void solve() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			char c;
			cin >> c;
			
			if (c == 'O')
				arr[i][j] = 1;
		}
	}

	for (int step = 0; step < (1<< MAX); step++) {
		init();
		
		int cnt = 0;
		
		for (int bit = 0; bit < MAX; bit++) {
			if (step & (1 << bit)) {
				cnt++;
				toggle(0, bit);
			}
		}
		
		for (int x = 1; x < MAX; x++) {
			for (int y = 0; y < MAX; y++) {
				if (tmpArr[x - 1][y]) {
					toggle(x, y);
					cnt++;
				}
			}
		}
        

		if (!islight())
			ans = min(cnt, ans);
	}

	if (ans == INF)
		cout << -1;
	else
		cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	solve();
}