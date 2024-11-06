#include <iostream>
#include <algorithm>
#include <set>

#define endl '\n'

using namespace std;

int N, n;
set<string> s;

void solve() {
	cin >> N;

	while (N--)
	{
		string temp, str;
		cin >> n;
		
		while (n--)
		{
			cin >> temp;
			str += ' ' + temp;
			s.insert(str);
		}
	}

	for (const auto& str : s)
	{
		int cnt = count(str.begin(), str.end(), ' ');
		int index = str.find_last_of(' ');
		string ans = str.substr(index + 1);

		for (int i = 0; i < 2 * (cnt - 1); ++i)
			cout << '-';
		cout << ans << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solve();
}
