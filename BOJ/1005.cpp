#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, k, w;
vector<int> building;
vector<vector<int>> order;
vector<int> dp;
vector<int> require;

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (require[i] == 0) {
            q.push(i);
            dp[i] = building[i];
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < order[x].size(); i++) {
            int next = order[x][i];
            if (next > 0) {
                dp[next] = max(dp[next], dp[x] + building[next]);
                require[next]--;
                if (require[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
}

void solve() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        building.clear(); building.resize(n + 1);
        dp.clear(); dp.resize(n + 1);
        require.clear(); require.resize(n + 1);
        order.clear(); order.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> building[i];
        }
        for (int i = 1; i <= k; i++) {
            int x, y;
            cin >> x >> y;
            order[x].push_back(y);
            require[y]++;
        }
        cin >> w;

        bfs();
        
        cout << dp[w] << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
