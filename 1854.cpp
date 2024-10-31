#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k, cost;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> heap[1001];
vector<pair<int, int>> v[1001];

void dijkstra() {
	pq.push(make_pair(0, 1));
	heap[1].push(0);
	
	while (!pq.empty()) {
		int x = pq.top().second;
		int num = pq.top().first;
		pq.pop();
		
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first;
			int cost = num + v[x][i].second;
			
			if (heap[next].size() < k) {
				heap[next].push(cost);
				pq.push(make_pair(cost, next));
			}
			else if (heap[next].top() > cost) {
				heap[next].pop();
				heap[next].push(cost);
				pq.push(make_pair(cost, next));
			}
		}
	}
}

void solve() {
	cin >> n >> m >> k;
    
	for (int i = 0; i < m; i++) {
		int dep, dest;
		cin >> dep >> dest >> cost;
		v[dep].push_back(make_pair(dest, cost));
    }
	
    dijkstra();
	
    for (int i = 1; i <= n; i++) {
		if (heap[i].size() < k) 
			cout << -1 << '\n';
		else 
			cout << heap[i].top() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();	
	return 0;
}