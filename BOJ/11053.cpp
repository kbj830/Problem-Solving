#include <iostream>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

int N, arr[1001], dp[1001];

void solve() {
	cin >> N;
	
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	
	int sum = 0;
    
	for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        sum = max(sum, dp[i]);
    }
    cout << sum << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
	return 0;
}
