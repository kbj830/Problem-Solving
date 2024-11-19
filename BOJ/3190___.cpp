#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, k, l, x, y, dir = 0, ans = 0;
int board[100][100];
queue<pair<int, int>> snake;
queue<pair<int, char>> rotations;

bool inRange(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < n;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        board[tmp1 - 1][tmp2 - 1] = 1;
    }
    
    x = 0, y = 0;
    snake.push({0, 0});
    board[0][0] = 2;

    cin >> l;
    for (int i = 0; i < l; i++) {
        int t; char rot;
        cin >> t >> rot;
        rotations.push({t, rot});
    }

    while (true) {
        ans++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!inRange(nx, ny) || board[nx][ny] == 2) {
            cout << ans << '\n';
            return;
        }
        
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
            snake.push({nx, ny});
        } else {
            board[nx][ny] = 2;
            snake.push({nx, ny});
            int tail_x = snake.front().first;
            int tail_y = snake.front().second;
            snake.pop();
            board[tail_x][tail_y] = 0;
        }
        
        x = nx;
        y = ny;

        if (!rotations.empty() && rotations.front().first == ans) {
            char rot = rotations.front().second;
            rotations.pop();
            if (rot == 'D') {
                dir = (dir + 1) % 4;
            } else {
                dir = (dir + 3) % 4;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
