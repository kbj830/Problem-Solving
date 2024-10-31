#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x) {
	if (parent[x] == x) 
		return x;
	
	return parent[x] = find(parent, parent[x]);
}

void unionSet(vector<int>& parent, int x, int y) {
	x = find(parent, x);
	y = find(parent, y);
	if (x != y) {
		parent[x] = y;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unionSet(parent, a, b);
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) {
			cnt++;
		}
	}
	
	cout << cnt - 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}