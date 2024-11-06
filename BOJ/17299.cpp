#include <iostream>
#include <stack>
#include <vector>

#define MAX 1000000

using namespace std;

int n;

void solve() {
	cin >> n;
	
	vector<int> arr(n + 1), ngf(n + 1, -1), cnt(MAX + 1);
	stack<int> s;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && cnt[arr[s.top()]] < cnt[arr[i]]) {
			ngf[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ngf[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
