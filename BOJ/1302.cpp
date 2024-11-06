#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, nSell = 0, maxSell = 0;
vector<string> book;
string best;

void solve() {
	cin >> n;
	book.resize(n);
	
	for (int i = 0; i < n; i++) 
		cin >> book[i];
	
	sort(book.begin(), book.end());
	
	if (n == 1) {
		cout << book[0] << '\n';
		return;
	}
	
	best = book[0];
	for (int i = 1; i < n; i++) {
		if (book[i] != book[i - 1]) {
			if (nSell > maxSell) {
				maxSell = nSell;
				best = book[i - 1];
			}
			nSell = 0;
		}
		else 
			nSell++;
	}
	if (nSell > maxSell)
		best = book[n - 1];
	
	cout << best << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
