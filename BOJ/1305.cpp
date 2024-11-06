#include <iostream>
#include <string>
#include <vector>

using namespace std;

int l;
string str, pat;
vector<int> table;

void solve() {
	cin >> l >> str;
	pat = str;
	table.resize(l + 1, 0);
	
	int j = 0;
	for (int i = 1; i < l; i++) {
		while (j && pat[j] != str[i]) {
			j = table[j - 1];
		}
		
		if (pat[j] == str[i]) {
			j++;
			table[i] = j;
		}
	}
	
	cout << l - table[l - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
