#include <iostream>
#include <queue>

using namespace std;

int board[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, k, l, dir = 0, ans = 0, x, y;
queue<pair<int, int>> snake;

bool inRange(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = -1;
    }
    
    cin >> l;
    int now = 0;
    snake.push({0, 0});
    board[0][0] = -1;
    int headR = 0, headC = 0;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        while (now < x) {
            headR += dx[dir];
            headC += dy[dir];
            now++;
            
            if (!inRange(headR, headC, n)) {
                cout << now << endl;
                return 0;
            }
            snake.push({headR, headC});
            if (board[headR][headC] == 1) {
                cout << now << endl;
                return 0;
            }
            if (board[headR][headC] == -1) {
                board[headR][headC] = 1;
                continue;
            }
            
            board[headR][headC] = 1;
            int tailR = snake.front().first;
            int tailC = snake.front().second;
            snake.pop();
            board[tailR][tailC] = 0;
        }
        if (c == 'L') {
            dir = (dir + 3) % 4;
        }
        if (c == 'D') {
            dir = (dir + 1) % 4;
        }
    }
    while (true) {
        headR += dx[dir];
        headC += dy[dir];
        now++;
        
        if (!inRange(headR, headC, n)) {
            break;
        }
        snake.push({headR, headC});
        if (board[headR][headC] == 1) {
            break;
        }
        if (board[headR][headC] == -1) {
            board[headR][headC] = 1;
        }
        else {
            board[headR][headC] = 1;
            int tailR = snake.front().first;
            int tailC = snake.front().second;
            snake.pop();
            board[tailR][tailC] = 0;
        }
    }
    cout << now << endl;
    
    return 0;
}
