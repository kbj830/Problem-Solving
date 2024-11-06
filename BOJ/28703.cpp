#include <iostream>
#include <queue>

using namespace std;

int n, limit, diff = 1e9 + 1;
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		
		maxPQ.push(tmp);
		minPQ.push(tmp);
	}
	
	limit = maxPQ.top();
	
	while (minPQ.top() <= limit) {
		int mn = minPQ.top();
		int mx = maxPQ.top();
		
		if (diff > mx - mn) 
			diff = mx - mn;
		
		minPQ.pop();
		minPQ.push(mn * 2);
		maxPQ.push(mn * 2);
	}
	
	cout << diff << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
