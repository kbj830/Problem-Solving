#include<iostream>
#include<algorithm>

using namespace std;

int ans = 100, cnt;
int usage[5] = {0,0,0,0,0};
int board[10][10];

bool findBlank(int x, int y, int s) {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (!board[x + i][y + j])
				return false;
        }
	}
	return true;
}

void change(int x, int y, int s, bool fill) {
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
				board[x + i][y + j] = fill;
}

void dfs(int x, int y, int attach) {
	while (board[x][y] == 0) {
		if (++y >= 10) {
			if (++x >= 10) {
				ans = min(ans, attach);
				return;
			}
			y = 0;
		}
	}

	if (ans <= attach)
		return;

	for (int s = 5; s > 0; s--) {
		if (x + s > 10 || y + s > 10 || usage[s] == 5) 
            continue;
		if (findBlank(x, y, s)) {
			change(x, y, s, 0);
			usage[s]++; 
			dfs(x, y, attach + 1);
			change(x, y, s, 1);
			usage[s]--;
		}
	}
}

void solve() {
    for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j]) cnt++;
		}
	}
	if (cnt == 10 * 10) {
		cout << 4 << '\n'; 
        return;
	}

	dfs(0, 0, 0);

	if (ans == 100) 
        ans = -1;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}