#include <iostream>
#include <vector>
#include <math.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int N, M, K;
ll arr[1000000];

ll makeSegmentTree(vector<ll> &segmentTree, int node, int s, int e) {
	if (s == e) {
		segmentTree[node] = arr[s];
		return segmentTree[node];
	}
	
	int m = (s + e) / 2;
	
	segmentTree[node] = makeSegmentTree(segmentTree, node * 2, s, m) + makeSegmentTree(segmentTree, node * 2 + 1, m + 1, e);
	return segmentTree[node];
}

void update(vector<ll> &segmentTree, int node, int s, int e,int idx, ll diff) {
	if (idx < s || idx > e)
		return;
	
	segmentTree[node] += diff;
	
	if (s != e) {
		int m = (s + e) / 2;
		
		update(segmentTree, node * 2, s, m, idx, diff);
		update(segmentTree, node * 2 + 1, m + 1, e, idx, diff);
	}
}

ll calSum(vector<ll> &segmentTree, int node, int l, int r, int s, int e) {
	if (l > e || r < s)
		return 0;
	
	if (l <= s && r >= e)
		return segmentTree[node];
	
	int m = (s + e) / 2;
	return calSum(segmentTree, node * 2, l, r, s, m) + calSum(segmentTree, node * 2 + 1, l, r, m + 1, e);
}

void solve() {
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int depth = ceil(log2(N));
	int size = 1 << (depth + 1);
	
	vector<ll> segmentTree(size);
	
	makeSegmentTree(segmentTree, 1, 0, N - 1);
	
	for (int i = 0; i < M + K; i++) {
		int act;
		ll l, r;
		
		cin >> act >> l >> r;
		
		if (act == 1) {
			update(segmentTree, 1, 0, N - 1, l - 1, r - arr[l - 1]);
			arr[l - 1] = r;
		}
		else {
			cout << calSum(segmentTree, 1, l - 1, r - 1, 0, N - 1) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}
