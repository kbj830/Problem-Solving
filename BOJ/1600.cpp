#include <iostream>
#include <queue>

using namespace std;

int hdx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int hdy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int k, w, h;
bool map[200][200];
int visit[200][200][31];

bool inRange(int x, int y) {
    if (x < 0 || x >= w || y < 0 || y >= h) 
        return 0;
    return 1;
}

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, k});
    visit[0][0][k] = 1;
    
    while(!q.empty()) {
        auto tmp = q.front();
        q.pop();
        int x = tmp.first.first, y = tmp.first.second, cnt = tmp.second;
        int move = visit[x][y][cnt];
        
        if (cnt) { // use horse move
            for (int i = 0; i < 8; i++) {
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                
                if (!inRange(nx, ny) || visit[nx][ny][cnt - 1] || map[nx][ny]) continue;

                visit[nx][ny][cnt - 1] = move + 1;
                q.push({{nx, ny}, cnt - 1});
                
                if (nx == w - 1 && ny == h - 1) return;
            }
        }
        for (int i = 0; i < 4; i++) { // move to adjacent square
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!inRange(nx, ny) || visit[nx][ny][cnt] || map[nx][ny]) continue;

            visit[nx][ny][cnt] = move + 1;
            q.push({{nx, ny}, cnt});
            
            if (nx == w - 1 && ny == h - 1) return;
        }
    }
}

void solve() {
	cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[j][i];
        }
    }
    
    bfs();
    
    for (int i = 0; i <= 30; i++) {
        if (visit[w - 1][h - 1][i]) {
            cout << visit[w - 1][h - 1][i] - 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
