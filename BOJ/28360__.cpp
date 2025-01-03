#include <iostream>
#include <vector>

using namespace std;

int n, m;
double ans;
vector<vector<int>> hose;
vector<double> bucket;

void solve() {
    cin >> n >> m;
    bucket.resize(n, 0);
    hose.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        hose[a].push_back(b);
    }
    for (int i = 0; i < n; i++) {
        int s = hose[i].size();
        for (int j = 0; j < s; j++) {
            bucket[hose[i][j]] += bucket[i]/s;
        }
        if (s > 0) {
            bucket[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, bucket[i]);
    }
    cout << fixed;
    cout.precision(10);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}