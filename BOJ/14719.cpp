#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w, ans = 0;
vector<int> block;
// vector<int> prefix;

void solve() {
	cin >> h >> w;
	block.resize(w);
	
	for (int i = 0; i < w; i++)
		cin >> block[i];
	
	for (int i = 1; i < w - 1; i++) {
		int l = 0, r = 0;
		
		for (int j = 0; j < i; j++)
			l = max(l, block[j]);
		for (int j = w - 1; j > i; j--)
			r = max(r, block[j]);
		
		ans += max(0, min(l, r) - block[i]);
	}
	
	cout << ans << '\n';
	
	// 1번째 코드
	/*
	cout << ans << '\n';
	
	block.resize(w);
	prefix.resize(w);
	for (int i = 0; i < w; i++) {
		cin >> block[i];
	}
	
	prefix[0] = block[0];
	for (int i = 1; i < w; i++) {
		prefix[i] = prefix[i - 1] + block[i];
	}
	
	int highest = block[0];
	for (int i = 0; i < w; i++) {
		if (block[i] >= highest) {
			ans += block[i] * 
		}
	}
	*/
	
	// 2번째 코드
	/*
	block.resize(w);
	
	int highest = 0;
	
	for (int i = 0; i < w; i++) {
		int height;
		cin >> height;
		block.push_back(height);
		highest = max(highest, height);
		
		if (highest > height) {
			for (int j = i - 1; j >= 0 && block[j] < height; j--) {
				block[j] = height;
				ans++;
				
				
				cout << j << " ";
			}
		}
	}
	
	cout << '\n';
	*/
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
