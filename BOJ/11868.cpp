#include <iostream>

#define endl '\n'

using namespace std;

int main() {
	int n, p;
	cin >> n;
	
	int x = 0;
	while (n--) {
		cin >> p;
		x ^= p;
	}
	
	if (!x)
		cout << "cubelover" << endl;
	else
		cout << "koosaga" << endl;
}
