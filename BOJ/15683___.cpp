#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
int map[8][8];
vector<pii> cam;

// check if (x,y) is in range of array
// return true if inside, false if outside.
bool inRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) 
        return false;
    return true;
}

// mark straight line
void fill(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    while(inRange(nx, ny)) {
        int type = map[nx][ny];
        // It's empty
        if (type <= 0) {
            map[nx][ny]--;
        }
        // There's a wall!!!
        else if (type == 6) {
            return;
        }
        nx += dx[dir];
        ny += dy[dir];
    }
}

// marks area watched by cam1-5
// cam1 : →
void one(int x, int y, int dir);
// cam2 : ← →
void two(int x, int y, int dir);
// cam3 : ↑ →
void three(int x, int y, int dir);
// cam4 : ← ↑ →
void four(int x, int y, int dir);
// cam5 : ← → ↑ ↓  ** mark in advance (area is fixed)
void five(int x, int y) {
    for (int i = 0; i < 4; i++) {
        fill(x, y, i);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
            if (tmp == 4) {
                four(i, j);
            }
            else if (tmp >= 1 && tmp <= 5) {
                cam.push_back({i, j});
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}