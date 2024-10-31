#include <iostream>

using namespace std;

int N, M, i, j, temp, arr[100002];

void solve() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[i + 1] = arr[i] + temp;
	}
	
	for (int k = 0; k < M; k++) {
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solve();
}