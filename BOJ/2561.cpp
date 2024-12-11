#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n;
int board[1000];
bool flag = false;
deque<pair<int,int>> ans;

bool isSeq(int a, int b, int c) {
    if ((a < b && b < c) || (a > b && b > c)) 
        return true;
    return false;
}

void reverse(int a, int b) {
    while(a < b) {
        int tmp = board[a];
        board[a] = board[b];
        board[b] = tmp;
        a++, b--;
    }
}

void dfs(int cnt) {
    vector<pair<int,int>> v;
    for (int i = 1; i < n + 2; i++) {
        if (abs(board[i] - board[i - 1]) > 1) {
            v.push_back({i - 1, i});
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if (!isSeq(board[i - 1], board[i], board[i + 1])) {
            v.push_back({i, i});
        }
    }
    if (v.empty()) {
        flag = true;
        for (int i = 0; i < 3 - ans.size(); i++) {
            ans.push_back({1, 1});
        }
        return;
    }
    if (cnt == 3) {
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            reverse(v[i].second, v[j].first);
            ans.push_back({v[i].second, v[j].first});
            dfs(cnt + 1);
            if (flag) {
                return;
            }
            reverse(v[i].second, v[j].first);
            ans.pop_back();
        }
    }
}

void solve() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    dfs(0);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
