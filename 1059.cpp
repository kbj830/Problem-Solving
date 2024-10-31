#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int s[51];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int l;
	cin >> l;
	
	for (int i = 0; i < l; i++) {
		cin >> s[i];
	}
	sort(s, s+l);
	
	int n;
	cin >> n;
	
	int idx = 0;
	while(n > s[idx]) idx++;
	
	if(n == s[idx]) {
		cout << 0 << endl;
		return 0;
	}
	
	idx--;
	
	cout << (n - s[idx]) * (s[idx + 1] - n) - 1 << endl;
}