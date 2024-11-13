#include <iostream>
#include <string>

using namespace std;

int n, x, s = 0;
string command;
int arr[10001];

void solve() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            cin >> x;
            arr[s] = x;
            s++;
        }
        else if (command == "pop") {
            if (s) {
                cout << arr[s - 1] << '\n';
                s--;
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (command == "size") {
            cout << s << '\n';
        }
        else if (command == "empty") {
            if (s) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else {
            if (s) {
                cout << arr[s - 1] << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}