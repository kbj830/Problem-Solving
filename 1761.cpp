#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

const int N = 4e4 + 4;

vector<pair<int, int>> v[N];
int dp[22][N], cost[N], lev[N];
bool visited[N];

void dfs(int cur, int prv) {
    visited[cur] = true;
    dp[0][cur] = prv;
    lev[cur] = lev[prv] + 1;
	
    for (auto [nxt, c] : v[cur]) {
        if (!visited[nxt]) {
            cost[nxt] = cost[cur] + c;
            dfs(nxt, cur);
        }
    }
}

int lca(int a, int b) {
    if (lev[a] > lev[b])
		swap(a, b);
    for (int i = 20; i >= 0; i--) {
		if (lev[b] - lev[a] >= (1 << i))
			b = dp[i][b];
    }
	if (a == b) return a;
	
	for (int i = 20; i >= 0; i--) { 
		if (dp[i][a] != dp[i][b]) {
			a = dp[i][a];
			b = dp[i][b];
		}
    }
    return dp[0][a];
}

void solve() {
	int n;
	cin >> n;
	
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
		cin >> a >> b >> c;
		
		v[a].push_back({b, c});
		v[b].push_back({a, c});
    }
	
    dfs(1, 0);

    for (int i = 1; i <= 20; i++)
		for (int j = 1; j < N; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
	
    int q;
	cin >> q;
	
    while (q--) {
		int a, b;
		cin >> a >> b;
        int _lca = lca(a, b);
        int ret = cost[a] + cost[b] - 2 * cost[_lca];   
        cout << ret << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
	return 0;
}