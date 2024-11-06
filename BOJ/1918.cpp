#include <iostream>
#include <stack>
#include <string>

using namespace std;
string str, ans = "";
stack<char> s;

void solve() {
	cin >> str;

    for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		
		if (c >= 'A' && c <= 'Z') {
			ans += c;
		}
		else {
			if (c == '(')
				s.push(c);
			else if (c == '*' || c == '/') {
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					ans += s.top();
					s.pop();
				}
				s.push(c);
			}
			else if (c == '+' || c == '-') {
				while (!s.empty() && s.top() != '(') {
					ans += s.top();
					s.pop();
				}
				s.push(c);
			}
			else if (c == ')') {
				while (!s.empty() && s.top() != '(') {
					ans += s.top();
					s.pop();
				}
				s.pop();
			}
		}
	}
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
