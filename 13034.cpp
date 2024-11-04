#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> grundy(1001, -1);

void solve() {
	cin >> n;
	
	grundy[0] = 0;
	grundy[1] = 0;
	grundy[2] = 1;
	
	for (int i = 3; i <= 1000; i++) {
		vector<int> cur(1001);
		for (int j = 0; j <= i / 2; j++)
			cur[grundy[j] ^ grundy[i - 2 - j]] = 1;
		
		for (int j = 0; j < i; j++) {
			if (cur[j] == 0) {
				grundy[i] = j;
				break;
			}
		}
	}

	if (grundy[n]) 
		cout << 1 << '\n';
	else 
		cout << 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
