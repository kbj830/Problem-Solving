#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

#define endl '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int N, M, K;
int arr[1000000];
vector<ll> tree;

ll makeTree(int node, int s, int e) {
    if (s == e) {
        return tree[node] = arr[s];
    }
	int m = (s + e) / 2;
    return tree[node] = makeTree(node * 2, s, m) * makeTree(node * 2 + 1, m + 1, e) % MOD;
}
ll update(int node, int s, int e, int idx, int num) {
    if (idx > e || idx < s)
		return tree[node];
    if (s == e)
		return tree[node] = num;
	
	int m = (s + e) / 2;
	
    return tree[node] = update(node * 2, s, m, idx, num) * update(node * 2 + 1, m + 1, e, idx, num) % MOD;
}
ll sum(int node, int s, int e, int l, int r) {
    if (l > e || r < s)
		return 1;
    if (l <= s && r >= e) 
        return tree[node];
	
	int m = (s + e) / 2;
	
    return sum(node * 2, s, m, l, r) * sum(node * 2 + 1, m + 1, e, l, r) % MOD;
}

void solve() {
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int depth = ceil(log2(N));
	int size = 1 << (depth + 1);
	
	tree.resize(size);
	
	makeTree(1, 0, N - 1);
	
	for (int i =0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
		if (a == 1)
            update(1, 0, N - 1, b - 1, c);
        else
            cout << sum(1 , 0, N - 1, b - 1, c - 1) << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    solve();
}