#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int jewel[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, ans;
    cin >> n >> m;
	
    for(int i = 0; i < m; i++) {
        cin >> jewel[i];
    }
	
    sort(jewel, jewel + m);

    int l = 1, r = jewel[m - 1];
    while(l <= r) {
        int mid = (l + r) / 2;
        
		int cnt = 0;
        for(int i = 0; i < m; i++) {
            cnt += jewel[i] / mid;
            if (jewel[i] % mid != 0)
				cnt++;
        }

        if (cnt <= n) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

}