#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SharkInfo {
    int r, c, s, d, z, idx;
};

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

int r, c, m, ans;
vector<int> ocean[101][101];
vector<SharkInfo> shark;

bool cmp(int a, int b) {
    return shark[a].z > shark[b].z;
}

bool chk() {
    for (auto& tmp : shark) {
        if (tmp.z != 0) 
            return false;
    }
    return true;
}

void fishing(int idx) {
    for (int i = 1; i <= r; i++) {
        if (!ocean[i][idx].empty()) {
            ans += shark[ocean[i][idx][0]].z;
            shark[ocean[i][idx][0]].z = 0;
            ocean[i][idx].clear();
            break;
        }
    }
}

void move() {
    for (auto& tmp : shark) {
        if (tmp.z == 0) 
            continue;
        ocean[tmp.r][tmp.c].clear();
    }

    for (auto& tmp : shark) {
        if (tmp.z == 0) 
            continue;
        int x = tmp.r, y = tmp.c, d = tmp.d, s = tmp.s;
        int rotate = (d <= 2 ? (r - 1) * 2 : (c - 1) * 2);
        s %= rotate;

        for (int j = 0; j < s; j++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 1 || nx > r) d = 3 - d, nx = x + dx[d];
            if (ny < 1 || ny > c) d = 7 - d, ny = y + dy[d];
            x = nx, y = ny;
        }

        tmp.r = x, tmp.c = y, tmp.d = d;
        ocean[x][y].push_back(tmp.idx);
    }
}

void dead() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (ocean[i][j].size() > 1) {
                sort(ocean[i][j].begin(), ocean[i][j].end(), cmp);
                for (int k = 1; k < ocean[i][j].size(); k++) {
                    shark[ocean[i][j][k]].z = 0;
                }
                ocean[i][j].resize(1);
            }
        }
    }
}

void solve() {
    cin >> r >> c >> m;
    for (int i = 0; i < m; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark.push_back({ r, c, s, d, z, i });
        ocean[r][c].push_back(i);
    }
    if (m == 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= c; i++) {
        if (chk()) 
            break;
        
        fishing(i);
        move();
        dead();
    }
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
