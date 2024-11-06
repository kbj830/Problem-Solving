#include <iostream>

#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	int n, k;
	while(true) {
		cin >> n >> k;
		if (!n)
			break;
		if (k > n - k)
			k = n - k;
		
		ll ans = 1;
		for(int i = 1; i <= k ; i++) {
			ans = ans * (n - i + 1) / i;
		}
		
		cout << ans << endl;
	}
}
