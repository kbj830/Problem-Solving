#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, h;
vector<vector<bool>> ladder;
int ans = 4;

// Determine if the ladder configuration is valid
bool check() {
    for (int i = 1; i <= n; i++) {
        int pos = i;
        for (int j = 1; j <= h; j++) {
            if (ladder[j][pos]) 
                pos++;
            else if (ladder[j][pos - 1]) 
                pos--;
        }
        if (pos != i) 
            return false;
    }
    return true;
}

void dfs(int cnt, int x, int y) {
    if (cnt >= ans) 
        return;
    if (check()) {
        ans = cnt;
        return;
    }
    if (cnt == 3) 
        return;

    for (int i = x; i <= h; i++) {
        for (int j = (i == x ? y : 1); j < n; j++) {
            if (!ladder[i][j] && !ladder[i][j - 1] && !ladder[i][j + 1]) {
                ladder[i][j] = true; // Add horizontal line
                dfs(cnt + 1, i, j + 2);
                ladder[i][j] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m >> h;
    ladder.assign(h + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    dfs(0, 1, 1);

    cout << (ans == 4 ? -1 : ans) << endl;

    return 0;
}
