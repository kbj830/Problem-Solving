#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

string inp;
stack<int> s;
vector<pair<int, int>> pos;
set<string> visit;
bool selection[10];
bool map[210];
vector<string> ans;

void dfs(int idx, int cnt) {
	if (cnt) {
		string str;
		for (int i = 0; i < inp.length(); i++) {
			if (!map[i]) 
				str += inp[i];
		}
		if (visit.find(str) == visit.end()) {
			visit.insert(str);
			ans.push_back(str);
		}
	}
	
	for (int i = idx; i < pos.size(); i++) {
		if (selection[i]) 
			continue;
		
		selection[i] = true;
		map[pos[i].first] = true;
		map[pos[i].second] = true;
		dfs(i, cnt + 1);
		selection[i] = false;
		map[pos[i].first] = false;
		map[pos[i].second] = false;
	}
}


void solve() {
	cin >> inp;
	
	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] == '(') 
			s.push(i);
		else if (inp[i] == ')') {
			int p = s.top();
			s.pop();
			pos.push_back(make_pair(p, i));
		}
	}
	
	dfs(0, 0);
	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}