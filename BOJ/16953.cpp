#include <iostream>

using namespace std;

int A, B;

int f(int b, int n) {
	if (b == A)
		return n;
	if (b < A)
		return -1;
	
	if (b % 10 == 1)
		return f(b/10, n + 1);
	if (b % 2 == 0)
		return f(b/2, n + 1);
	
	return -1;
}

void solve() {
	cout << f(B, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> A >> B;
	
	solve();
}
