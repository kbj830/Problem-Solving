#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool cmp(int a, int b) {
	return a > b;
}

void solve() {
	ll n;
	cin >> n;
	
	vector<int> v;
	
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

int main() {
	solve();
	return 0;
}
