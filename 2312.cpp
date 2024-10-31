#include <iostream>
#include <math.h>

#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		for (int i = 2, cnt;; ++i) {
            cnt = 0;
            if (n == 1) {
                break;
            }
            while (n% i == 0) {
                cnt++;
                n /= i;
            }
            if (cnt != 0) {
                cout << i << " " << cnt << endl;
            }
        }
	}
}