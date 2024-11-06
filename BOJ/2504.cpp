#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> s;
int ans = 0, tmp = 1;

void solve() {
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		
		if (str[i] == '(') {
			s.push('(');
			tmp *= 2;
		}
		else if (str[i] == '[') {
			s.push('[');
			tmp *= 3;
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() == '[') {
				ans = 0;
				break;
			}
			if (str[i - 1] == '(')
				ans += tmp;
			tmp /= 2;
			s.pop();
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() == '(') {
				ans = 0;
				break;
			}
			if (str[i - 1] == '[')
				ans += tmp;
			tmp /= 3;
			s.pop();
		}
	}
	
	if (s.empty())
		cout << ans << '\n';
	else 
		cout << 0 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
