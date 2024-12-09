#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int w, b, high, cnt;
string longest;
bool found;
char map[4][4];
bool visit[4][4];
vector<string> dict;

// check if (x, y) is within the range of the map and has been visited
bool canmove(int x, int y) {
    if (x < 0 || x >= 4 || y < 0 || y >= 4 || visit[x][y]) 
        return false;
    return true;
}

// find the word in the map using dfs and backtracking
void dfs(string word, int idx, int x, int y) {
    int l = word.length();
    if (idx == l - 1) {
        found = true;
        high += score[l];
        int mxl = longest.length();
        if (l > mxl) {
            longest = word;
        }
        // length is same, compare 'word' and 'answer' alphabetically.
        if (l == mxl) {
            longest = min(word, longest);
        }
        cnt++;
        return;
    }

    visit[x][y] = true;
    char next = word[idx + 1];
    
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!canmove(nx, ny)) 
            continue;
        
        if (map[nx][ny] == next) {
            dfs(word, idx + 1, nx, ny);
            if (found) 
                break;
        }
    }
    visit[x][y] = false;
}

void boggle(string word) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == word[0]) {
                found = false;
                dfs(word, 0, i, j);
                // exclude the redundant
                if (found) 
                    return;
            }
        }
    }
}

void solve() {
	cin >> w;
    dict.resize(w);
    for (int i = 0; i < w; i++) {
        cin >> dict[i];
    }
    
    cin >> b;
    while (b--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> map[i][j];
            }
        }
        
        // reset variables before starting the game
        high = 0;
        cnt = 0;
        longest = "";
        
        for (int i = 0; i < dict.size(); i++) {
            boggle(dict[i]);
        }

        cout << high << ' ' << longest << ' ' << cnt << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
