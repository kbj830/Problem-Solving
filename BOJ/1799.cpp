#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, 1, -1};

int n;
int b[10][10];
int visit[10][10];
int ans[2];

bool check(int x, int y, int res[][10]) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j] * i;
            int ny = y + dy[j] * i;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (res[nx][ny] == -1) {
                    return false;
                }
            }
        }
    }
    return true;
}

// -1 : bishop, 0 : empty, 1 : cannot place
void dfs(int x, int y, int res[][10], int c, int k, vector<pair<int, int>> a) {
    if (x == n) {
        ans[k] = max(ans[k], c);
        return;
    }
    if (y == n - 1) dfs(x + 1, 0, res, c, k, a);
    else dfs(x, y + 1, res, c, k, a);

    if (res[x][y] == 0) 
        return;
    if (visit[x][y] == k) 
        return;

    if (check(x, y, res)) {
        res[x][y] = -1;
        a.push_back({x, y});
        if (y == n - 1) dfs(x + 1, 0, res, c + 1, k, a);
        else dfs(x, y + 1, res, c + 1, k, a);
        res[x][y] = 1;
        a.pop_back();
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
            if ((i + j) % 2 == 0) 
                visit[i][j] = 1;
        }
    }

    vector<pair<int, int>> a;

    dfs(0, 0, b, 0, 0, a);
    dfs(0, 0, b, 0, 1, a);

    cout << ans[0] + ans[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
