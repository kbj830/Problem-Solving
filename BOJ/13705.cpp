#include <iostream>

using namespace std;

__float128 myPi = 3.1415926535897932384626Q;

__float128 mySin(__float128 x) {
	x -= (__int128)(x / myPi) * myPi;
	__float128 rt = x, k = x, p = -x * x;
	for(__float128 i = 2; i < 30; i += 2) {
		k *= p / (i * (i + 1));
		rt += k;
	}
	return rt;
}

int main() {
	int a, b, c;
	
	cin >> a >> b >> c;
	
	__float128 A = a, B = b, C = c;
	__float128 l = (C - B) / A, r = (C + B) / A, x;
	
	for(int i = 0; i < 100; i++) {
		x = (l + r) / 2;
		if (A * x + B * mySin(x) < C)
			l = x;
		else
			r = x;
	}

	printf("%Lf\n", (long double)(__int128(x * 1000000 + 0.5) / 1000000.0));
}
