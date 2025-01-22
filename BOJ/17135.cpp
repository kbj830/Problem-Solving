#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct T {
    int r, c, d;
};

int n, m, d;
int ans;
int map[15][15];
int nmap[15][15];
vector<int> archer;

bool cmp(T &a, T &b) {
    if (a.d == b.d) 
        return a.c < b.c;
    return a.d < b.d;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = nmap[i][j];
        }
    }
}

int attack() {
    int ret = 0;
    int t = n;
    
    while (t) {
        vector<pair<int, int>> del;
        for (auto &k: archer) {
            vector<T> target;
            for (int i = 0; i < t; i++) {
                for (int j = 0; j < m; j++) {
                    if (!map[i][j]) 
                        continue;
                    if (dist(i, j, t, k) > d) 
                        continue;
                    
                    target.push_back({i, j, dist(i, j, t, k)});
                }
            }
            if (target.empty()) 
                continue;
            
            sort(target.begin(), target.end(), cmp);
            
            del.push_back({target[0].r, target[0].c});
        }
        
        for (auto &k: del) {
            if (map[k.first][k.second] == 1) {
                map[k.first][k.second] = 0;
                ret++;
            }
        }

        t--;
    }
    return ret;
}

void comb(int idx, int k) {
    if (k == 0) {
        copy();
        ans = max(ans, attack());
        return;
    }
    
    for (int i = idx + 1; i < m; i++) {
        archer.push_back(i);
        comb(i, k - 1);
        archer.pop_back();
    }
}

void solve() {
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    comb(0, 3);
    
    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
