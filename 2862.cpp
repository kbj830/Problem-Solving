#include <iostream>

#define endl '\n'

typedef long long ll;

using namespace std;

ll fib[100];

int main() {
	fib[0] = 1, fib[1] = 2;
	for (int i = 2; i < 100; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	
	ll n;
	cin >> n;
	for (int i = 76; n != fib[i] && i >= 0; i--) {
		if (n > fib[i])
			n -= fib[i];
	}
	
	cout << n << endl;
}