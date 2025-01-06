#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int n, ans = 1e9;
ll s;
ll prefix[100000];

void solve() {
	cin >> n >> s;
    
    if (s == 0) {
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp == 0) {
                cout << 1 << '\n';
                return;
            }
        }
        cout << 0 << '\n';
        return;
    }
    
    cin >> prefix[1];
    if (prefix[1] >= s) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        prefix[i] = prefix[i-1] + tmp;
    }
    
    int l = 0, r = 0;
    while(true) {
        ll tmp = prefix[r] - prefix[l];
        if (tmp >= s) {
            ans = min(ans, r - l);
            if (l < r) 
                l++;
            else 
                r++;
        }
        else {
            r++;
        }
        if (r > n) {
            break;
        }
    }

    if (ans == 1e9) 
        cout << 0 << '\n';
    else 
        cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
