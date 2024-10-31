#include <iostream>

#define endl '\n'

using namespace std;

typedef long long ll;

int N;
int A[500001];
int B[1000001];
int tree[500001*4];

ll sum(int node, int s, int e, int l, int r) {
	if (e<l || s>r)
		return 0;

	if (l<= s && e <= r)
		return tree[node];

	int m = (s + e) / 2;
	
	return sum(node * 2, s, m, l, r) + sum(node * 2 + 1, m + 1, e, l, r);
}

void update(int node, int s, int e, int idx) {
	if (s > idx || e < idx)
		return;
	
	if (s == e) {
		tree[node] = 1;
		return;
	}
	
	int m = (s + e) / 2;
	
	update(node * 2, s, m, idx);
	update(node * 2 + 1, m + 1, e, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void solve() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		B[num] = i;
	}

	ll res = 0;
	for (int i = 0; i < N; i++) {
		res += sum(1, 0, N - 1, B[A[i]]+1, N - 1);
		update(1, 0, N - 1, B[A[i]]);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}