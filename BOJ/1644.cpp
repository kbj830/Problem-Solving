#include <iostream>
#include <vector>

using namespace std;

#define MAX 4000001

int n, ans = 0;
vector<bool> isPrime(MAX, true);
vector<int> prefix;

void findPrime() {
    prefix.push_back(0);
    for (int i = 2; i < MAX; i++) 
        if (isPrime[i]) {
            prefix.push_back(prefix.back() + i);
            for (int j = i * 2; j < MAX; j += i) 
                isPrime[j] = false;
        }
}

void solve() {
    cin >> n;
	findPrime();
    for (int i = 0; i < prefix.size(); i++) {
        for (int j = i + 1; j < prefix.size() && prefix[j] - prefix[i] <= n; j++) {
			if (prefix[j] - prefix[i] == n) {
                ans++;
			}
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    findPrime();
    solve();
    return 0;
}
