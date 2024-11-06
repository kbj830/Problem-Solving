#include <iostream>
#include <math.h>

using namespace std;

double x, y, c, l = 0, r, mid;

void solve() {
	cin >> x >> y >> c;
	r = min(x, y);
	
	while(true) {
		mid = (l + r) / 2;
		double tmp = (sqrt(y*y - mid*mid) * sqrt(x*x - mid*mid)) / (sqrt(y*y - mid*mid) + sqrt(x*x - mid*mid));
		if (fabs(c - tmp) < 0.000001) {
			break;
		}
		else if (c < tmp) 
			l = mid;
		else 
			r = mid;
	}

	cout << mid << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
