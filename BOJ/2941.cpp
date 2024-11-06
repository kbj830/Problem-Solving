#include <iostream>
#include <string>

using namespace std;

string croatian[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

void solve() {
	string str;
	cin >> str;
	
	int idx;
	
	for (int i = 0; i < 8; i++) {
		while (true) {
			idx = str.find(croatian[i]);
			if (idx == string::npos)
				break;
			str.replace(idx, croatian[i].length(), "*");
		}
	}
	
	cout << str.length() << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
