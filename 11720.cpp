#include <iostream>

using namespace std;

int main() {
	int N, k, sum = 0;
	cin >> N;
	
	while(N--) {
		scanf("%1d", &k);
		sum += k;
	}
	
	cout << sum << endl;
}