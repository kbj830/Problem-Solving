#include <iostream>
#include <algorithm>
#include <math.h>

#define endl '\n'

using namespace std;

int myRound(double n) {
	return floor(n + 0.5);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	int* arr = (int *)malloc(sizeof(int) * n);
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	int exclude = myRound(n * 0.15), sum = 0;
	
	for(int i = exclude; i < n - exclude; i++) {
		sum += arr[i];
	}
	
	cout << (int)myRound((double)sum / (n - 2 * exclude)) << endl;
	
	free(arr);
}
