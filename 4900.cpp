#include <iostream>
#include <string>
#include <map>
using namespace std;

string code[10] = {
	"063", "010", "093", "079", "106", 
	"103", "119", "011", "127", "107"
};

int seg2dec(string str) {
	int num = 0;
	for (int i = 0; i < str.length(); i += 3) {
		num *= 10;
		for (int j = 0; j < 10; j++) {
			if (str.substr(i, 3) == code[j]) {
				num += j;
				break;
			}
		}
	}
	return num;
}

string dec2seg(int n) {
	string str = to_string(n);
	string ret = "";
	for (int i = 0; i < str.length(); i++) {
		ret += code[str[i] - '0'];
	}
	return ret;
}

void solve() {
	string str, first, second;
	int split;
	while (true) {
		cin >> str;
		if (str == "BYE")
			return;
		
		split = str.find('+');
		first = str.substr(0, split);
		second = str.substr(split + 1, str.length() - split - 2);
		cout << str << dec2seg(seg2dec(first) + seg2dec(second)) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}