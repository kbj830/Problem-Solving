#include<iostream>
#include<stack>

#define endl '\n'

using namespace std;

long long hist[100001];

void solve() {
	while (true) {
		stack<int> s;
		int n;
		long long max = -1;
		
		cin >> n;
		
		if (n == 0)
			break;
		
		for (int i = 0; i < n; i++)
			cin >> hist[i];
		
		for (int i = 0; i < n; i++)	{
			while (!s.empty() && hist[i] < hist[s.top()])
			{
				long long t = hist[s.top()];
				
				int l = i;
				s.pop();
				
				if (!s.empty())
					l = i - s.top() - 1;
				
				if (max < l * t)
					max = l * t;
			}
			
			s.push(i);
		}
		
		while (!s.empty()) {
			long long t = hist[s.top()];
			int l = n;
			s.pop();
			
			if (!s.empty())
				l = n - s.top() - 1;
			
			if (max < l * t)
				max = l * t;
		}
		
		cout << max << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solve();
}