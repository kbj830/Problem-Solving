#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> v;

int goodNum(int x, int i) {
    int l = 0, r = n - 1, sum;
    while(l < r) {
        sum = v[l] + v[r];
        if (sum == x) {
            if (l != i && r != i) {
                return 1;
            }
            if (l == i) l++;
            if (r == i) r--;
        }
        else if (sum < x) l++;
        else r--;
    }
    return 0;
}

void solve() {
	cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++) {
        ans += goodNum(v[i], i);
    }

    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
