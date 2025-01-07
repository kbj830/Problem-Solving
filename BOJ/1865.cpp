#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct edge {
	int s, e, t;
};

int tc, n, m, w;

bool BellmanFord(int n, vector<edge> edges) {
	vector<int> dist(n + 1, 1e9);
	int s, e, t;
	dist[1] = 0;
    
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t) 
				dist[e] = dist[s] + t;
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (dist[e] > dist[s] + t) 
			return true;
	}
	return false;
}

void solve() {
	cin >> tc;
	while(tc--) {
		cin >> n >> m >> w;
		vector<edge> edges;
        int s, e, t;
        // road
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edges.push_back({s, e, t});
			edges.push_back({e, s, t});
		}
        // wormhole
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edges.push_back({s, e, -t});
		}

		if (BellmanFord(n, edges)) 
            cout << "YES" << '\n';
		else 
            cout << "NO" << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}