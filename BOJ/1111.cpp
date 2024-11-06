#include <iostream>

using namespace std;

int N, num[50];

void solve() {
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> num[i];

	if (N == 1) {
		cout << "A" << endl;
		return;
	}
	if (N == 2) {
		if (num[0] == num[1])
			cout << num[1] << endl;
		else
			cout << "A" << endl;
		return;
	}
	
	int a = 0;
	
	if (num[1] - num[0] != 0)
		a = (num[2] - num[1]) / (num[1] - num[0]);

	int b = num[1] - num[0] * a;

	for (int i = 1; i < N; i++) {
		if (num[i] != num[i - 1] * a + b){
			cout << "B" << endl;
			return;
		}
	}

	cout << num[N - 1] * a + b << endl;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
