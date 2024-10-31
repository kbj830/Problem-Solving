#include <iostream>

int n, m;

int gcd(int a, int b) {
	if (b > a)
		return gcd(b, a);
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

void solve() {
	scanf("%d:%d", &n, &m);
	int d = gcd(n, m);
	printf("%d:%d\n", n / d, m / d);
}

int main() {
	solve();
	return 0;
}