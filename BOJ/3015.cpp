#include <iostream>
#include<stack>

#define endl '\n'

using namespace std;

int N;

void solve() {
	cin >> N;

	stack<pair<int,int>> st;
	int input, same = 0;
	long long cnt = 0;

	for(int i = 0; i < N; i++) {
		cin >> input;
		
		same = 1;
		while(!st.empty() && st.top().first < input) {
			cnt += st.top().second;
			st.pop();
		}
		
		if(!st.empty()) {
			if(st.top().first == input) {
				cnt += st.top().second;
				same = (st.top().second +1 );
				
				if(st.size() >1)
					cnt++;
				
				st.pop();
			}
			else {
				cnt++;
			}
		}
		st.push(make_pair(input, same));
	}

	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
