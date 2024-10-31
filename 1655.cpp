#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;

void solve() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		
		if (maxPQ.empty() || maxPQ.size() == minPQ.size()) 
			maxPQ.push(tmp);
		else 
			minPQ.push(tmp);
		
		if (!maxPQ.empty() && !minPQ.empty() && maxPQ.top() > minPQ.top()) {
			int mx = maxPQ.top();
			int mn = minPQ.top();
			
			maxPQ.pop();
			minPQ.pop();
			
			maxPQ.push(mn);
			minPQ.push(mx);
		}
		
		cout << maxPQ.top() << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}