#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<int> net[101];
bool visited[101];

void search(int pos) {
    visited[pos] = true;
    for (int i = 0; i < net[pos].size(); i++) {
		int npos = net[pos][i];
		if (!visited[npos]) {
			ans++;
			search(npos);
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        net[s].push_back(e);
        net[e].push_back(s);
    }
    search(1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;    
}