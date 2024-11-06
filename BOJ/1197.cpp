#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

typedef pair<int, pair<int, int>> mypair;

int V, E, A, B, C;
vector<mypair> v;
int parent[10001];
int ans;

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

void solve() {
    cin >> V >> E;
	
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v.push_back({C, {A, B}});
    }
	
    sort(v.begin(), v.end());
	
	for(int i = 1; i <= V; i++)
		parent[i] = i;
	
    int cnt = 0;
	
    for(int i = 0; i < v.size(); i++){
		mypair curEdge = v[i];
		int cost = curEdge.first;
		int now = curEdge.second.first;
		int next = curEdge.second.second;
		
		if(findParent(now) != findParent(next)) {
			unionParent(now, next);
			ans += cost;
			if(cnt == V - 2) 
				break;
		}
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
    return 0;
}
