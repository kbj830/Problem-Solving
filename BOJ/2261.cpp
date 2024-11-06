#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> PAIR;

int n, ans;
vector<PAIR> v;
set<PAIR> s;

int dist(PAIR a, PAIR b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x * x + y * y;
}

void solve() {
	cin >> n;
    for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
    }
	
	sort(v.begin(), v.end());
	s.insert({v[0].second, v[0].first});
	s.insert({v[1].second, v[1].first});
	
	ans = dist(v[0], v[1]);
	
	int idx = 0;
	for (int i = 2; i < n; ++i) {
		while (idx < i) {
			int d = v[i].first - v[idx].first;
			
			if (d * d > ans) {
				s.erase({v[idx].second, v[idx].first});
				idx++;
			}
			else 
				break;
		}
		
		auto start = s.lower_bound({ v[i].second - sqrt(ans), -100000 });
		auto end = s.upper_bound({ v[i].second + sqrt(ans), 100000 });
		
		for (auto tmp = start; tmp != end; tmp++) 
			ans = min(ans, dist({ tmp->second, tmp->first }, v[i]));
		
		s.insert({ v[i].second, v[i].first });
	}
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
