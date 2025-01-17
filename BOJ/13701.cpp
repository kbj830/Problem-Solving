#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int x;
bitset<1<<25> b;

void solve() {
	while(cin >> x) {
        if (!b[x]) {
            cout << x << ' ';
            b[x] = 1;
        }
    }
    cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}