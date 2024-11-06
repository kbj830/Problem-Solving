#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cmath>

#define endl '\n'

using namespace std;

vector<deque<int>> gear(5);
int rotation[5];
bool check[5];
int k;

void setRotation(int g, int d) {
	rotation[g] = d;
	check[g] = true;
	if (g - 1 > 0 && !check[g - 1]) {
		if (d == 0)
			setRotation(g - 1, 0);
		else if (gear[g][6] == gear[g - 1][2])
			setRotation(g - 1, 0);
		else
			setRotation(g - 1, -d);
    }
	
	if (g + 1 <= 4 && !check[g + 1]) {
		if (d == 0)
			setRotation(g + 1, 0);
		else if (gear[g][2] == gear[g + 1][6])
			setRotation(g + 1, 0);
		else
			setRotation(g + 1, -d);
	}
}

void rotate() {
	for (int i = 1; i <= 4; i++) {
		if (rotation[i] == 0)
			continue;
		if (rotation[i] == 1) {
			int temp = gear[i].back();
			gear[i].pop_back();
			gear[i].push_front(temp);
		}
		else {
			int temp = gear[i].front();
			gear[i].pop_front();
			gear[i].push_back(temp);
		}
	}
}

int getScore() {
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
		if (gear[i][0] == 1) {
			ans += pow(2, i - 1);
		}
	}
	return ans;
}

void solve() {
    char n;
    for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> n;
			gear[i].push_back(n - '0');
		}
	}
	
	cin >> k;
	int g, d;
	
	while (k--) {
		cin >> g >> d;
		memset(check, false, sizeof(check));
		setRotation(g, d);
		rotate();
	}
	int ans = getScore();
	cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
