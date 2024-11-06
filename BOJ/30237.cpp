#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int sum(int *arr) {
	int rt = 0;
	
	for(int i = 0; i < 51; i++) {
		rt += arr[i];
	}
	
	return rt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int elements[51] = {0, }, min = 50;
		
		while(n--) {
			int k;
			cin >> k;
			
			if (k < min)
				min = k;
			while(k--) {
				int s;
				cin >> s;
				elements[s] = 1;	
			}
		}
		
		cout << sum(elements) - min << endl;
	}
}
