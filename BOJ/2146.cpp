#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 100

int map[MAX][MAX];
int n, ans = 1e9;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int>> edges;

void labeling(int x, int y, int label) {
    queue<pair<int, int>> q;
    q.push({x, y});
    map[x][y] = label;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        bool isEdge = false;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (map[nx][ny] == -1) {
                    map[nx][ny] = label;
                    q.push({nx, ny});
                } else if (map[nx][ny] == 0) {
                    isEdge = true;
                }
            }
        }

        if (isEdge) {
            edges.push_back({cx, cy});
        }
    }
}

int findShortestBridge() {
    int minDist = 1e9;
    for (size_t i = 0; i < edges.size(); i++) {
        int x1 = edges[i].first;
        int y1 = edges[i].second;

        for (size_t j = 0; j < edges.size(); j++) {
            if (i != j) {
                int x2 = edges[j].first;
                int y2 = edges[j].second;

                if (map[x1][y1] != map[x2][y2]) {
                    int dist = abs(x1 - x2) + abs(y1 - y2) - 1;
                    minDist = min(minDist, dist);
                }
            }
        }
    }
    return minDist;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                map[i][j] = -1;
            }
        }
    }

    int label = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == -1) {
                labeling(i, j, label++);
            }
        }
    }

    cout << findShortestBridge() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
