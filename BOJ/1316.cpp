#include <iostream>
#include <string.h>

using namespace std;

int alpha[26];

void clearArr() {
	for (int i = 0; i < 26; i++) {
		alpha[i] = 0;
	}
}

bool isGroup(string str) {
	alpha[str[0] - 'a'] = 1;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[i - 1] && alpha[str[i] - 'a'])
			return false;
		alpha[str[i] - 'a'] = 1;
	}
	return true;
}

void solve() {
	int n, ans = 0;
	string str;
	cin >> n;
	
	while (n--) {
		clearArr();
		cin >> str;
		if (isGroup(str))
			ans++;
	}
	cout << ans << endl;
}


int main() {
	solve();
	return 0;
}
