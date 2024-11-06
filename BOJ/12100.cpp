#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int n;
int board[21][21];
int ans = 0;


void move(int type) {
	queue<int> q;
	
	if (type == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
				board[i][j] = 0;
			}
			
			int idx = 1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				
				if(board[i][idx] == 0) {
					board[i][idx] = data;
				}
				else if (board[i][idx] == data) {
					board[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					board[i][idx] = data;
				}
			}
		}
	}
	else if (type == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
				board[i][j] = 0;
			}
			
			int idx = n;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				
				if (board[i][idx] == 0) {
					board[i][idx] = data;
				}
				else if (board[i][idx] == data) {
					board[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					board[i][idx] = data;
				}
			}
		}
	}
	else if (type == 2) {
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
				board[i][j] = 0;
			}
			
			int idx = 1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				
				if (board[idx][j] == 0) {
					board[idx][j] = data;
				}
				else if (board[idx][j] == data) {
					board[idx][j] *= 2;
					idx++;
				}
				else {
					idx++;
					board[idx][j] = data;
				}
			}
		}
	}
	else if (type == 3) {
		for (int j = 1; j <= n; j++) {
			for (int i = n; i >= 1; i--) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
				board[i][j] = 0;
			}
			
			int idx = n;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				
				if (board[idx][j] == 0) {
					board[idx][j] = data;
				}
				else if (board[idx][j] == data) {
					board[idx][j] *= 2;
					idx--;
				}
				else {
					idx--;
					board[idx][j] = data;
				}
			}
		}
	}
}

void dfs(int depth) {
	if (depth == 5) 
		return;

	int temp[21][21];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			temp[i][j] = board[i][j];

	for (int i = 0; i < 4; i++) {
		move(i);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] > ans) {
					ans = board[i][j];
				}
			}
		}
		
		dfs(depth + 1);
		
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				board[j][k] = temp[j][k];
			}
		}
	}
}

void solve() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0);

	cout << ans << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
