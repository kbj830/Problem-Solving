#include <iostream>
#include <string>
#include <vector>

using namespace std;

void perm(string str, string ans) {
	int len = str.length();
	if (!len) {
		cout << ans << '\n';
		return;
	}
	for (int i = 0; i < len; i++) {
		perm(str.substr().erase(i, 1), ans + str[i]);
	}
}

void solve() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string str;
		cin >> str;
		cout << "Case # " << i << ":\n";
		perm(str, "");
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
