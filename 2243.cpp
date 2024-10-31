#include <iostream>
#include <vector>

#define endl '\n'
#define MAX 1000000

using namespace std;

int n, q, r, idx, diff;
vector<int> tree;

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || idx > e)
		return;
	
	tree[node] += diff;
	
    if (s < e) {
		int m = (s + e) / 2;
		update(node * 2, s, m, idx, diff);
		update(node * 2 + 1, m + 1, e, idx, diff);
	}
}

int findnum(int node, int s, int e, int r) {
    if(s == e)
		return s;
    
	int m = (s + e) / 2;
    
	if (r <= tree[node * 2])
		return findnum(node * 2, s, m, r);
	return findnum(node * 2 + 1, m + 1, e, r - tree[node * 2]);
}

void solve() {
	cin >> n;
	
    tree.resize(4 * MAX + 1);
    for (int i = 0; i < n; i++) {
		cin >> q;
		
		if(q == 1) {
			cin >> r;
			
			idx = findnum(1, 1, MAX, r);
			
			cout << idx << endl;
			
			update(1, 1, MAX, idx, -1);
		}
		else {
			cin >> idx >> diff;
			update(1, 1, MAX, idx, diff);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}