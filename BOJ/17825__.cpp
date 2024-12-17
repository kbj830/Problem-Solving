#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// Paths of the game board
vector<int> board[4] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0},
    {0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40, 0},
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40, 0},
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40, 0}
};

int dice[10];
int ans;

vector<bool> visited[4];
map<pair<int, int>, vector<pair<int, int>>> common;
vector<pair<int, int>> horses = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

void dfs(int cnt, int score) {
    if (cnt >= 10) {
        ans = max(ans, score);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int road = horses[i].first, pos = horses[i].second;
        // Reached the end -> skip
        if (pos == board[road].size() - 1) 
            continue;
        
        int nRoad = road, nPos = pos + dice[cnt];
        if (road == 0 && (pos == 5 || pos == 10 || pos == 15)) 
            nRoad = pos / 5;
        nPos = min(nPos, int(board[nRoad].size()) - 1);
        
        // Already visted -> skip
        if (nPos != board[nRoad].size() - 1 && visited[nRoad][nPos]) 
            continue;
        
        vector<pair<int, int>> commons = common[{road, pos}], nCommons = common[{nRoad, nPos}];
        for (auto &h : commons) 
            visited[h.first][h.second] = false;
        for (auto &h : nCommons) 
            visited[h.first][h.second] = true;
        
        horses[i] = {nRoad, nPos};
        dfs(cnt + 1, score + board[nRoad][nPos]);
        horses[i] = {road, pos};
        
        for (auto &h : commons) 
            visited[h.first][h.second] = true;
        for (auto &h : nCommons) 
            visited[h.first][h.second] = false;
    }
}


void solve() {
    // Set up common positions on the board
    common[{0, 5}] = common[{1, 5}] = common[{2, 5}] = common[{3, 5}] = {{0, 5}, {1, 5}, {2, 5}, {3, 5}};
    common[{0, 10}] = common[{1, 10}] = common[{2, 10}] = common[{3, 10}] = {{0, 10}, {1, 10}, {2, 10}, {3, 10}};
    common[{0, 15}] = common[{1, 15}] = common[{2, 15}] = common[{3, 15}] = {{0, 15}, {1, 15}, {2, 15}, {3, 15}};
    common[{0, 20}] = common[{1, 12}] = common[{2, 16}] = common[{3, 22}] = {{0, 20}, {1, 12}, {2, 16}, {3, 22}};
    for (int i = 0; i < 3; i++) {
        vector<pair<int, int>> t = {{1, 9 + i}, {2, 13 + i}, {3, 19 + i}};
        for (auto &h : t) common[h] = t;
    }
    
    for (int i = 0; i < 4; i++)
        visited[i].assign(board[i].size(), false);
    
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
    
    dfs(0, 0);
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
