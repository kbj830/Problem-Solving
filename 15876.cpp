#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	int cnt = 0, num = 0, binDigit = 1, order = 1, next = k;
	
	while (cnt < 5) {
		int temp = num;
		while (num >= 1 << binDigit) {
			binDigit++;	
		}
		
		int bin[8];
		for (int i = binDigit - 1; i >= 0; i--) {
			if (temp % 2)
				bin[i] = 1;
			else
				bin[i] = 0;
			
			temp /= 2;
		}
		
		for (int i = 0; i < binDigit; i++, order++) {
			if (order == next) {
				cout << bin[i] << " ";
				cnt++;
				next += n;
				
				if (cnt == 5)
					return 0;
			}
		}
		num++;
	}
}