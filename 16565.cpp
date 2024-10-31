#include <iostream>

#define MOD 10007
#define endl '\n'

using namespace std;

int N, comb[53][53];

void solve() {
	cin>>N;
    for (int i = 0; i <= 52; i++) {
        comb[i][0] = 1;
		comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            comb[i][i - j] = comb[i][j];
        }
    }
	
    int anw = 0;
	
    for (int i = 4; i <= N; i += 4){
        if ((i / 4) % 2 == 1) {
            anw += comb[13][i / 4] * comb[52 - i][N - i];
        }
        else {
            anw -= comb[13][i / 4] * comb[52 - i][N - i];
        }
		
        anw %= 10007;
    }
	
    if (anw < 0)
		anw += MOD;
	
    cout << anw << endl;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   solve();
}