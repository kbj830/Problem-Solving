#include <iostream>
#include <stack>

typedef long long ll;

using namespace std;

int n, tmp;
stack<int> s;
ll ans = 0;

void solve() {
	cin >> n;
	
	cin >> tmp;
	s.push(tmp);
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		while(!s.empty() && s.top() <= tmp) {
			s.pop();
		}
		ans += s.size();
		s.push(tmp);
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
