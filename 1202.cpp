#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 300001

using namespace std;

typedef long long ll;

int n, k;
ll ans = 0;
pair<int, int> jewel[MAX];
int bag[MAX];
priority_queue<int> pq;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	
	sort(jewel, jewel + n);
	sort(bag, bag + k);
	
	int i = 0, j = 0;
	for (; i < k; i++) {
		for (; j < n && bag[i] >= jewel[j].first; j++) 
			pq.push(jewel[j].second);
		
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}