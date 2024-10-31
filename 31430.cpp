#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

void gap() {
	ll a, b;
	cin >> a >> b;
	
	string str = "aaaaaaaaaaaaa";
	ll sum = a + b;
	
	for (int i = 0; i < 13; i++) {
		str[12 - i] = sum % 26 + 'a';
		sum /= 26;
	}
	cout << str << '\n';
}

void eul() {
	string str;
	cin >> str;
	ll res = 0, mul = 1;
	for (int i = 0; i < 13; i++) {
		res += (str[12 - i] - 'a') * mul;
		mul *= 26;
	}
	cout << res << '\n';
}

void solve() {
	int t;
	cin >> t;
	
	if (t == 1)
		gap();
	else
		eul();
}

int main() {
	solve();
	return 0;
}