#include <iostream>
#include <string>

using namespace std;

int n, k, idx = 0;
string num, ans = "";

void solve() {
	cin >> n >> k;
	cin >> num;
	
	for (int i = 0; i < num.length(); i++) {
		while(!ans.empty() && k && num[i] > ans.back()) {
			k--;
			ans.pop_back();
		}
		ans += num[i];
	}
	ans.erase(ans.length() - k, k);
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}