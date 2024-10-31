#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
bool map[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int v) {
	cout << v << ' ';
	visited[v] = true;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] && !visited[i])
			dfs(i);
	}
}

void bfs(int v) {
	q.push(v);
	visited[v] = true;
	cout << v << ' ';
	
	while(!q.empty()) {
		v = q.front();
		q.pop();
		
		for (int i = 1; i <= n; i++) {
			if (map[v][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cout << i << ' ';
			}
		}
	}
}

void solve() {
	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = true;
		map[b][a] = true;
	}
	
	dfs(v);
	cout << '\n';
	
	for (int i = 1; i <= 1001; i++) 
		visited[i] = false;
	
	bfs(v);
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}