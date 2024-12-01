#include <iostream>
#include <queue>

#define MAX 2000

using namespace std;

int s;
bool visit[MAX][MAX];

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1, 0), 0));
    visit[1][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int clip = q.front().first.second;
        int t = q.front().second;
        q.pop();

        if (x == s) 
            return t;

        if (x > 0 && x < MAX) {
            if (!visit[x][x]) {
                visit[x][x] = true;
                q.push(make_pair(make_pair(x, x), t + 1));
            }
            if (!visit[x - 1][clip]) {
                visit[x - 1][clip] = true;
                q.push(make_pair(make_pair(x - 1, clip), t + 1));
            }
        }

        if (clip > 0 && x + clip < MAX) {
            if (!visit[x + clip][clip]) {
                visit[x + clip][clip] = true;
                q.push(make_pair(make_pair(x + clip, clip), t + 1));
            }
        }
    }
    return -1;
}

void solve() {
    cin >> s;

    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1, 0), 0));
    visit[1][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int clip = q.front().first.second;
        int t = q.front().second;
        q.pop();

        if (x == s) {
            cout << t << '\n';
            return;
        }

        if (x > 0 && x < MAX) {
            if (!visit[x][x]) {
                visit[x][x] = true;
                q.push(make_pair(make_pair(x, x), t + 1));
            }
            if (!visit[x - 1][clip]) {
                visit[x - 1][clip] = true;
                q.push(make_pair(make_pair(x - 1, clip), t + 1));
            }
        }

        if (clip > 0 && x + clip < MAX) {
            if (!visit[x + clip][clip]) {
                visit[x + clip][clip] = true;
                q.push(make_pair(make_pair(x + clip, clip), t + 1));
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
