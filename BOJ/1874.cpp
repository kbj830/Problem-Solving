#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, cnt = 1;
vector<char> ans;
stack<int> s;

void solve() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (cnt <= x) {
            s.push(cnt);
            cnt++;
            ans.push_back('+');
        }
        if (s.top() == x) {
            s.pop();
            ans.push_back('-');
        }
        else {
            cout << "NO" << '\n';
            return;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
