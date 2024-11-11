#include <iostream>
#include <deque>
 
using namespace std;
 
#define MAX 100001
 
int n, k;
int visited[MAX];
 
void bfs() {
    deque<int> dq;
    dq.push_back(n);
    visited[n] = 1;

    while (!dq.empty()) {
        int x = dq.front();
        dq.pop_front();

        if(x == k) 
            return;

        if (x * 2 < MAX && !visited[x * 2]) {
            dq.push_front(x * 2);
            visited[x * 2] = visited[x];
        }
        if (x - 1 >= 0 && !visited[x - 1]) {
            dq.push_back(x - 1);
            visited[x - 1] = visited[x] + 1;
        }
        if (x + 1 < MAX && !visited[x + 1]) {
            dq.push_back(x + 1);
            visited[x + 1] = visited[x] + 1;
        }
    }
}

void solve() {
    cin >> n >> k;
    bfs();
    cout << visited[k] - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}