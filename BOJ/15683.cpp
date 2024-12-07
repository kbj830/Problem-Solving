#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m, ans, ncam;
int map[8][8];
vector<pair<pair<int,int>,int>> cam;
vector<pair<int,int>> cam5;

int cntArea() {
    int rt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) rt++;
        }
    }

    return rt;
}

// check if (x,y) is in range of map
bool inRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return true;
}

// mark straight line (1 : fill, 0 : erase)
void change(int x, int y, int dir, bool fill) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    while(inRange(nx, ny)) {
        int type = map[nx][ny];
        // There's a wall!!!
        if (type == 6) {
            return;
        }
        // It's empty
        else if (type <= 0) {
            if (fill) {
                map[nx][ny]--;
            }
            else {
                map[nx][ny]++;
            }
        }
        nx += dx[dir];
        ny += dy[dir];
    }
}

// marks area watched by cam1-5
// cam1 : →
void one(int x, int y, int dir, bool fill) {
    change(x, y, dir, fill);
}
// cam2 : ← →
void two(int x, int y, int dir, bool fill) {
    change(x, y, dir, fill);
    change(x, y, (dir + 2) % 4, fill);
}
// cam3 : ↑ →
void three(int x, int y, int dir, bool fill) {
    change(x, y, dir, fill);
    change(x, y, (dir + 1) % 4, fill);
}
// cam4 : ← ↑ →
void four(int x, int y, int dir, bool fill) {
    change(x, y, dir, fill);
    change(x, y, (dir + 1) % 4, fill);
    change(x, y, (dir + 2) % 4, fill);
}
// cam5 : ← → ↑ ↓  **The sight is fixed
void five(int x, int y) {
    for (int i = 0; i < 4; i++) {
        change(x, y, i, true);
    }
}

void control(pair<pair<int,int>,int> c, int dir, bool fill) {
    int type = c.second;
    int x = c.first.first;
    int y = c.first.second;
    if (type == 1) {
        one(x, y, dir, fill);
        return;
    }
    if (type == 2) {
        two(x, y, dir, fill);
        return;
    }
    if (type == 3) {
        three(x, y, dir, fill);
        return;
    }
    four(x, y, dir, fill);
}

void dfs(int idx) {
    if (idx == ncam) {
        ans = min(cntArea(), ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        control(cam[idx], i, true);
        dfs(idx + 1);
        control(cam[idx], i, false);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
            if (tmp == 5) {
                cam5.push_back({i, j});
            }
            else if (tmp >= 1 && tmp <= 4) {
                cam.push_back({{i, j}, tmp});
                ncam++;
            }
        }
    }

    for (int i = 0; i < cam5.size(); i++) {
        five(cam5[i].first, cam5[i].second);
    }
    ans = cntArea();
    dfs(0);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}