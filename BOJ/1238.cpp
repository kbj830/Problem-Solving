#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
vector<pair<int, int>> adj[1001];
int dist[1001], result[1001];
int n, m, x;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;

    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (cost > dist[now]) continue;

        for (auto [next, weight] : adj[now]) {
            if (cost + weight < dist[next]) {
                dist[next] = cost + weight;
                pq.emplace(dist[next], next);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].emplace_back(v, t);
    }

    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
        result[i] = dist[x];
    }

    dijkstra(x);

    for (int i = 1; i <= n; ++i) {
        result[i] += dist[i];
    }

    cout << *max_element(result + 1, result + n + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
