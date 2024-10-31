#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int a, b, n;
	cin >> n >> a >> b;
	
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	
	int cnt = 0;
	
	while(a % 2 != 1 || b - a > 1) {
		a++;
		a /= 2;
		b++;
		b /= 2;
		
		cnt++;
	}
	
	cout << ++cnt;
	
}