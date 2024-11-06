#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<double> score;

double julsa() {
	double sum = 0;
	for (int i = k; i < n - k; i++) {
		sum += score[i];
	}
	return sum / (n - 2 * k) + 0.00000001;
}

double bojung() {
	double sum = k * (score[k] + score[n - k - 1]);
	for (int i = k; i < n - k; i++) {
		sum += score[i];
	}
	return sum / n + 0.00000001;
}

void solve() {
	cin >> n >> k;
	
	score.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	
	sort(score.begin(), score.end());
	
	cout << fixed;
	cout.precision(2);
	
	cout << julsa() << '\n' << bojung() << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
