#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define endl '\n'
#define INF 2e9
#define MAX_N 100001

using namespace std;

int N, M;
int minVal, maxVal;
vector<int>arr;
vector<int>minTree;
vector<int>maxTree;

int makeMinTree(int node, int s, int e) {

	if (s == e) {
		minTree[node] = arr[s];
		return minTree[node];
	}

	int leftNode = node * 2;
	int rightNode = node * 2 + 1;
	int m = (s + e) / 2;

	int leftRes = makeMinTree(leftNode, s, m);
	int rightRes = makeMinTree(rightNode, m + 1, e);
	minTree[node] = min(leftRes, rightRes);

	return minTree[node];
}


int makeMaxTree(int node, int s, int e) {

	if (s == e) {
		maxTree[node] = arr[s];
		return maxTree[node];
	}

	int leftNode = node * 2;
	int rightNode = node * 2 + 1;
	int m = (s + e) / 2;

	int leftRes = makeMaxTree(leftNode, s, m);
	int rightRes = makeMaxTree(rightNode, m + 1, e);
	maxTree[node] = max(leftRes, rightRes);

	return maxTree[node];
}

int minQuery(int node, int s, int e, int l, int r) {

	if (l > e || r < s) {
		return INF;
	}
	if (l <= s && e <= r) {
		return minTree[node];
	}

	int leftNode = node * 2;
	int rightNode = node * 2 + 1;
	int m = (s + e) / 2;

	int leftRes = minQuery(leftNode, s, m, l, r);
	int rightRes = minQuery(rightNode, m + 1, e, l, r);
	int minVal = min(leftRes, rightRes);

	return minVal;
}

int maxQuery(int node, int s, int e, int l, int r) {

	if (l > e || r < s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return maxTree[node];
	}

	int leftNode = node * 2;
	int rightNode = node * 2 + 1;
	int m = (s + e) / 2;

	int leftRes = maxQuery(leftNode, s, m, l, r);
	int rightRes = maxQuery(rightNode, m + 1, e, l, r);
	int maxVal = max(leftRes, rightRes);

	return maxVal;
}

void solve() {
	cin >> N >> M;
	
	arr.clear();
	minTree.clear();
	maxTree.clear();
	
	arr.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int h = ceil(log2(N));
	int size = (1 << (h + 1));
	minTree.resize(size);
	maxTree.resize(size);

	makeMinTree(1, 0, N - 1);
	makeMaxTree(1, 0, N - 1);
	
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		
		minVal = minQuery(1, 0, N - 1, a - 1, b - 1);
		maxVal = maxQuery(1, 0, N - 1, a - 1, b - 1);
		
		
		cout << minVal << " " << maxVal << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
