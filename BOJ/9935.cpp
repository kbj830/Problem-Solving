#include <iostream>
#include <string>

using namespace std;

string str, explo, ans = "";

void solve() {
	cin >> str >> explo;
	
	int sLen = str.length(), eLen = explo.length();
	for (int i = 0; i < sLen; i++) {
		ans += str[i];
		if (ans.length() >= eLen) {
			if (ans.substr(ans.length() - eLen).compare(explo) == 0)
				ans.erase(ans.end() - eLen, ans.end());
		}
	}
	
	if (ans.empty())
		cout << "FRULA\n";
	else 
		cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
