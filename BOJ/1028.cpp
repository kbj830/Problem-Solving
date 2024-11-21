#include <iostream>

using namespace std;

#define MAX 752

int n, m, ans = 0;
int input[MAX][MAX], dp[MAX][MAX][2];

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            input[i][j] = tmp - '0';
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (input[i][j]) {
                dp[i][j][0] = dp[i + 1][j - 1][0] + 1;
                dp[i][j][1] = dp[i + 1][j + 1][1] + 1;
            }
            else {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l = min(dp[i][j][0], dp[i][j][1]) - 1;

            if (l < 0)
                continue;

            int ret = 1;
            for (int k = 1; k <= l; k++) {
                if (i + k >= n || j + k >= m || j - k < 0)
                    continue;

                if (min(dp[i + k][j - k][1], dp[i + k][j + k][0]) >= k + 1)
                    ret = k + 1;
            }
            ans = max(ans, ret);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
