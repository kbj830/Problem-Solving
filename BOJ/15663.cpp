#include <iostream>
#include <algorithm>

using namespace std;

int N, M, input[10], ans[10];
bool check[10];

void findSeq(int l) {
	if (l == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	int temp = 0;
	for (int i = 0; i < N; i++) {
		if (!check[i] && temp != input[i]) {
			ans[l] = input[i];
			temp = input[i];
			check[i] = true;
			findSeq(l + 1);
			check[i] = false;
		}
	}
}

void solve() {
	sort(input, input + N);	
	findSeq(0);
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
		cin >> input[i];
	
	solve();
}
