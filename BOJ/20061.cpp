#include <iostream>
#include <algorithm>

using namespace std;

int n, block = 0, ans = 0;
int board[10][10];

void move(int t, int x, int y) {
	int i, j;
	
	if (t == 1) {
		i = x;
		while (i < 9 && !board[i+1][y]) 
			i++;
		
		j = y;
		while (j < 9 && !board[x][j+1]) 
			j++;
		
		board[i][y] = 1;
		board[x][j] = 1;
		
		return;
	}
	
	if (t == 2) {
		i = x;
		while (i < 9 && !board[i+1][y] && !board[i+1][y+1]) 
			i++;
		
		j = y + 1;
		while (j < 9 && !board[x][j+1]) 
			j++;
		
		board[i][y] = 1; board[i][y+1] = 1;
		board[x][j] = 1; board[x][j-1] = 1;
		
		return;
	}
	
	if (t == 3) {
		i = x + 1;
		while (i < 9 && !board[i+1][y]) 
			i++;
		
		j = y;
		while (j < 9 && !board[x][j+1] && !board[x+1][j+1]) 
			j++;
		
		board[i-1][y] = 1; board[i][y] = 1;
		board[x][j] = 1; board[x+1][j] = 1;
		
		return;
	}
}

void remove() {
	int start = -1, removed = 0;
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (!board[i][j]) 
				break;
			
			if (j == 3) {
				start = max(start, i);
				removed++;
			}
		}
	}

	if (start > -1) {
		for (int i = start - removed; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				board[i + removed][j] = board[i][j];
				board[i][j] = 0;
			}
		}
		ans += removed;
	}

	start = -1, removed = 0;
	for (int j = 6; j < 10; j++) {
		for (int i = 0; i < 4; i++) {
			if (!board[i][j]) 
				break;
			
			if (i == 3) {
				start = max(start, j);
				removed++;
			}
		}
	}

	if (start > -1) {
		for (int j = start - removed; j >= 4; j--) {
			for (int i = 0; i < 4; i++) {
				board[i][j + removed] = board[i][j];
				board[i][j] = 0;
			}
		}
		ans += removed;
	}
}

void invasion() {
	int r = 0, c = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j]) {
				r++;
				break;
			}
		}
	}

	if (r > 0) {
		for (int i = 9 - r; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				board[i + r][j] = board[i][j];
			}
		}
		for (int i = 4; i <= 5; i++) {
			for (int j = 0; j < 4; j++) {
				board[i][j] = 0;
			}
		}
	}

	for (int j = 4; j <= 5; j++) {
		for (int i = 0; i < 4; i++) {
			if (board[i][j]) {
				c++;
				break;
			}
		}
	}

	if (c > 0) {
		for (int j = 9 - c; j >= 4; j--) {
			for (int i = 0; i < 4; i++) {
				board[i][j + c] = board[i][j];
			}
		}
		for (int j = 4; j <= 5; j++) {
			for (int i = 0; i < 4; i++) {
				board[i][j] = 0;
			}
		}
	}
}

void solve() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		move(t, x, y);
		remove();
		invasion();
	}
	
	for (int i = 0; i < 4; i++) 
		for (int j = 6; j < 10; j++) 
			if (board[i][j]) 
				block++;

	for (int i = 6; i < 10; i++) 
		for (int j = 0; j < 4; j++) 
			if (board[i][j]) 
				block++;
	
	cout << ans << '\n' << block << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
