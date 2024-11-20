#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
vector<pair<int,int>> v;
int ans[500000];
int tree[2000000];

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    return a.second > b.second;
}

int sum(int start, int end) {
    int l = start + s - 1;
    int r = end + s - 1;
    int ret = 0;
    while (l <= r) {
        if ((l & 1) == 1) {
            ret += tree[l];
            l++;
        }
        if ((r & 1) == 0) {
            ret += tree[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back({i, tmp});
    }
    
    sort(v.begin(), v.end(), cmp);

    s = 1;
    while(s < n) s *= 2;

    for (int i = 0; i < n; i++) {
        int rank = v[i].first;
        int idx = rank + s;
        tree[idx] = 1;

        for(idx /= 2; idx >= 1; idx /= 2) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
        }
        ans[rank] = sum(1, rank) + 1;
    }

    for (int i = 0; i < n; i++) 
        cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
