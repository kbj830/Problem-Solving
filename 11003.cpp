#include <iostream>
#include <queue>

using namespace std;

int n, l;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(make_pair(tmp, i));
		
		while (pq.top().second < i - l + 1) 
			pq.pop();
		
		cout << pq.top().first << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}