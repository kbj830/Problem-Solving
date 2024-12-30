#include <iostream>

using namespace std;

int n, ans = 0;
int board[20][20];

// push blocks to the left
bool move(int v[][20]) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (v[i][j]) {
                int idx = j;
                while (idx && !v[i][idx-1]) {
                    flag = true;
                    swap(v[i][idx-1], v[i][idx]);
                    idx--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            // merge blocks
            if (v[i][j] && v[i][j+1] && v[i][j] == v[i][j+1]) {
                flag = true;
                v[i][j] *= 2;
                v[i][j+1] = 0;
                int idx = j+1;
                while (idx < n-1) {
                    swap(v[i][idx], v[i][idx+1]);
                    idx++;
                }
            }
        }
    }
    return flag;
}

// rotate the board clockwise
void rotate(int v[][20], int nboard[][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nboard[j][n-1-i] = v[i][j];
        }
    }
}

int findMax(int v[][20]) {
    int rt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            if (v[i][j] > rt) {
                rt = v[i][j];
            }
        }
    }
    return rt;
}

void dfs(int cnt, int v[][20]) {
    int curmax = findMax(v);
    // cannot make bigger number in remaining attempts
    if (curmax << (10-cnt) <= ans) {
        return;
    }
    if (cnt == 10) {
        ans = max(ans, curmax);
        return;
    }

    int nboard[4][20][20] = {};
    rotate(v, nboard[0]);
    for (int i = 1; i < 4; i++) {
        rotate(nboard[i-1], nboard[i]);
    }    
    for (int i = 0; i < 4; i++) {
        // move blocks (if nothing moved, continue)
        if (move(nboard[i])) {
            dfs(cnt+1, nboard[i]);            
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    ans = findMax(board);
    dfs(0, board);
    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
